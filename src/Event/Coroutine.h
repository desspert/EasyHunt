#pragma once
#include "../../Cinder/include/boost/coroutine/all.hpp"

struct CoroutineInfo
{
	CoroutineInfo(float time_, std::function<void()> func_) :
		time(time_),
		callback(func_)
	{
		  
	}
	float time;
	std::function<void()> callback;
};
