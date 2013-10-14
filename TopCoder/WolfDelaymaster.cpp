#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

int dp[55][55];
string ss;

int counter(int s, int e){
    int nw = 0, sum = 0,in;
    for (in=s;in<=e;in++)
        if (ss[in]=='w')
            nw++;
        else break;
    if (nw==0)
        return 0;
    for (;in<=e;in++)
        if (ss[in]=='o')
            sum++;
        else break;
    if (sum!=nw)
        return 0;
    sum = 0;
    for (;in<=e;in++)
        if (ss[in]=='l')
            sum++;
        else break;
    if (sum!=nw)
        return 0;
    sum = 0;
    for (;in<=e;in++)
        if (ss[in]=='f')
            sum++;
        else break;
    if (sum!=nw)
        return 0;
    if (in>e)
        return 1;
    else return 0;
}

int isv(int s, int e){
    if (s==e||s>e)
        return 0;
    if (dp[s][e]!=-1)
        return dp[s][e];
    if (counter(s,e))
        return dp[s][e] = 1;
    dp[s][e] = 0;
    for (int i=s+1;i<e;i++){
        if (isv(s,i)&&isv(i+1,e)){
            return dp[s][e] = 1;
        }
    }
    return 0;
}

class WolfDelaymaster {
public:
	string check(string str) {
        memset(dp,-1,sizeof dp);
        ss = str;
        return isv(0,str.size()-1)?"VALID":"INVALID";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	WolfDelaymaster *obj;
	string answer;
	obj = new WolfDelaymaster();
	clock_t startTime = clock();
	answer = obj->check(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	string p0;
	string p1;

	{
	// ----- test 0 -----
	p0 = "wolf";
	p1 = "VALID";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = "wwolfolf";
	p1 = "INVALID";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = "wolfwwoollffwwwooolllfffwwwwoooollllffff";
	p1 = "VALID";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = "flowolf";
	p1 = "INVALID";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
