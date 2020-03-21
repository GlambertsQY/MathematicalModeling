#include "Header.h"

Thread::Thread(int p, int st, int ot, int iiR, int iiW)
{
    pos = p;
    startTime = st;
    overTime = ot;
    isinRQ = iiR;
    isinWQ = iiW;
}

Thread::Thread()
{
    pos = -1;
    startTime = -1;
    overTime = -1;
    isinRQ = 0;
    isinWQ = 0;
}

void Thread::InRQ()
{
    isinRQ = 1;
}

void Thread::OutRQ()
{
    isinRQ = 0;
}

void Thread::InWQ()
{
    isinWQ = 1;
}

void Thread::OutWQ()
{
    isinWQ = 0;
}

int Thread::GetSTime()
{
    return startTime;
}

int Thread::GetOTime()
{
    return overTime;
}

int Thread::GetPos()
{
    return pos;
}

RGV::RGV()
{
    RGVTime = 0;
    RGVPos = 0;
}

void RGV::AddTime(int at)
{
    RGVTime += at;
}

void RGV::SetPos(int p)
{
    RGVPos = p;
}

int RGV::GetDistantTime(Thread t)
{
    switch (abs((t.GetPos() - 1) / 2 - RGVPos))
    {
    case 0:
        return 0;
        break;
    case 1:
        return RGVMOVE1;
        break;
    case 2:
        return RGVMOVE2;
        break;
    case 3:
        return RGVMOVE3;
        break;
    default:
        return -1;
        break;
    }
    return 0;
}

int RGV::GetRGVTime()
{
    return RGVTime;
}

void Schedule::Init()
{
    vehicle.AddTime(CNCWORKINGTIME);
    vehicle.SetPos(3);
    Thread *t1 = new Thread(1, RGVUUTO, RGVUUTE + CNCWORKINGTIME, 1, 0);
    RQ.push_back(*t1);
    Thread *t2 = new Thread(2, RGVUUTO + RGVUUTE, RGVUUTO + RGVUUTE + CNCWORKINGTIME, 0, 1);
    WQ.push_back(*t2);
    for (int i = 2; i < 8; i++)
    {
        if (i % 2 != 0)
        {
            Thread *t = new Thread(i + 1, WQ.back().GetSTime() + RGVMOVE1 + RGVUUTO, WQ.back().GetOTime() + RGVMOVE1 + RGVUUTO, 0, 1);
            WQ.push_back(*t);
        }
        else if (i % 2 == 0)
        {
            Thread *t = new Thread(i + 1, WQ.back().GetSTime() + RGVUUTE, WQ.back().GetOTime() + RGVUUTE, 0, 1);
            WQ.push_back(*t);
        }
    }
}

Schedule::Schedule() {}

int Schedule::Start()
{

    return 0;
}
