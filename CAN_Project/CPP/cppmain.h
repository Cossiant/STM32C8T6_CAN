#ifndef CPPMAIN_H
#define CPPMAIN_H

#ifdef __cplusplus
extern "C"
{
#endif
//这里添加CPP函数，因为CPP无法正确被C调用，因此要进行转换
	void CPP_Main();
	void CPP_Main_While();
#ifdef __cplusplus
}
#endif

#endif