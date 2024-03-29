#ifndef TEXTMANAGER__H
#define TEXTMANAGER__H

#include <vector>
#include <deque>
#include <string>

using namespace std;

class GTerm;

class TextManager
{
public:
	TextManager(GTerm* parent = NULL, int width = 80, int height = 24, int maxWidth = 160, int maxHeight = 100);

	int GetSize();
	int GetMaxSize();
	int GetHeight();
	int GetNumLinesScrolled();
	int GetLinesReceived();
	string& GetLine(int index);
	string& GetLineAdjusted(int index);
	char GetCharAdjusted(int y, int x);
	unsigned short GetColor(int y, int x);
	unsigned short GetColorAdjusted(int y, int x);


	void CursorDown();
	void CursorUp();

	void SetMaxSize(int newSize);
	void SetCharAdjusted(int y, int x, char c);
	void SetCursorLine(int line);
	void SetLine(int index, string line);
	void SetLineAdjusted(int index, string line);
	void SetColor(int y, int x, unsigned short value);
	void SetColorAdjusted(int y, int x, unsigned short value);
	
	void SetHeight(const int newHeight);
	
	void PrintViewport();
	void PrintContents();
	void PrintToBitmap();

	void AddNewLine();
	void AddNewLine(string newline);
	void Scroll(int numLines, bool scrollUp);
	void Resize(int width, int height);
	void Reset();

	string& operator[](int index);

private:

	int AdjustIndex(int index);

	int m_topLine;
	int m_bottomLine;
	int m_numLinesScrolledUp;
	int m_viewportHeight;
	int m_viewportWidth;
	int m_linesReceived;
	int m_maxHeight;
	int m_maxWidth;
	int m_cursorLine;
	int m_blankColor;
	string m_blankline;

	deque< vector<unsigned short> > m_color;
	deque<string> m_text;
	
	GTerm* m_parent;
};








#endif