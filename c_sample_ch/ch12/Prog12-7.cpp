#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
#define X_MAX 10 // 定義可活動的範圍
#define Y_MAX 10 // 定義可活動的範圍
class CMouse // 老鼠走路 V1.1 版
{
private:
	int ix, iy;		// 老鼠的起始位置
	int iStatus;	
	char cIcon;
public:
	void Init();
	void Show();
	int  Update(char cIn);
	int  GetStatus(){return(iStatus);}
};
void CMouse::Init() {
	ix = 1, iy =1; // 老鼠的起始位置
	iStatus = 1;   // 1 : 正常狀態, 2: 離開邊界 0: 死亡狀態
	cIcon ='@';
}
void CMouse::Show() {
	system("cls"); // 清除螢幕上的顯示
	for( int i = 1 ; i <= ix ; i++ ) cout << endl;
	cout << setw(iy+1) << setfill(' ') << cIcon << endl;
}
int  CMouse::Update(char cIn)
{
		switch(cIn) {
			case 'w': // 往上，更改老鼠位置，並根據新的位置，更新老鼠的狀態
				ix--;
				if( ix < 0 ) iStatus = 0; // 老鼠超過邊界，死亡
				else if( ix == 0 ) {iStatus = 2; cIcon = 'Q';}// 走到邊界上
				else if( iy >= 1 && iy <= Y_MAX ) {iStatus = 1; cIcon = '@';}
				break;
			case 's': // 往下
				ix++;
				if( ix > X_MAX + 1 ) iStatus = 0;		// 老鼠超過邊界，死亡
				else if( ix == X_MAX+1 ) {iStatus = 2; cIcon = 'Q';}// 走到邊界上
				else if( iy >= 1 && iy <= Y_MAX ) {iStatus = 1; cIcon = '@';}
				break;
			case 'a': // 往左
				iy--;
				if( iy < 0 ) iStatus = 0; // 老鼠超過邊界，死亡
				else if( iy == 0 )  {iStatus = 2; cIcon = 'Q';}// 走到邊界上
				else if( ix >= 1 && ix <= X_MAX ) {iStatus = 1; cIcon = '@';} 
				break;
			case 'd': // 往右
				iy++;
				if( iy >  Y_MAX + 1 ) iStatus = 0; // 老鼠超過邊界，死亡
				else if( iy == Y_MAX+1 ) {iStatus = 2; cIcon = 'Q';}// 走到邊界上
				else if( ix >= 1 && ix <= X_MAX ) {iStatus = 1; cIcon = '@';}
				break;
		}
	return(iStatus);	// 傳回老鼠的狀態
}
int main(void)
{
	char cIn;
	int iStatus;
	CMouse mouseX;
	mouseX.Init(); // 設定老鼠的初始狀態
	mouseX.Show(); // 讓老鼠自己畫出自己的位置
	iStatus = mouseX.GetStatus();
//	iStatus = mouseX.iStatus; // 嘗試存取私有區域的變數，會產生編譯錯誤
	while( iStatus != 0 ) { // 只要老鼠還在正常狀態就繼續讓使用者輸入
		cIn = getch();
		iStatus = mouseX.Update(cIn); // 讓老鼠自己更新狀態
		if( iStatus ) mouseX.Show(); // 只要老鼠沒有死亡，就必須更新老鼠位置的顯示
		else cout << "老鼠已經死亡,遊戲結束" << endl;
	}
	system("pause"); return(0);
}