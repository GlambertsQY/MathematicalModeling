#ifndef FCFS_H_
#define FCFS_H_

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int RGVMOVE1 = 20;
const int RGVMOVE2 = 33;
const int RGVMOVE3 = 46;
const int CNCWORKINGTIME = 560;
const int RGVUUTO = 28;
const int RGVUUTE = 31;
const int RGVWASH = 25;
const int TIMELIMIT = 28800; //8hr

class Thread
{
private:
	int pos;
	int startTime;
	int overTime;
	int isinRQ;
	int isinWQ;

public:
	Thread(int, int, int, int, int);
	Thread();
	void InRQ();
	void OutRQ();
	void InWQ();
	void OutWQ();
	int GetSTime();
	int GetOTime();
	int GetPos();
};

class RGV
{
private:
	int RGVTime;
	int RGVPos;
public:
	RGV();
	void AddTime(int);
	void SetPos(int);
	int GetDistantTime(Thread);
	int GetRGVTime();
};

class Schedule
{
private:
	vector<Thread> RQ;
	vector<Thread> WQ;
	vector<Thread> OQ;
	RGV vehicle;
public:
	Schedule();
	void Init();
	int Start();
};



#endif