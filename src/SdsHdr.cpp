//
// Created by againstsky on 2024/9/23.
//

#include "SdsHdr.h"

#include <cstring>

namespace againstsky {
    sedis::SdsHdr::SdsHdr(const char *str):SdsHdr(str,str==nullptr?0:strlen(str)){

    }

    sedis::SdsHdr::SdsHdr(const char *str, const int initlen) {
        if (str) {
            _data = new char[initlen + 1];
        } else {
            //内存初始化为0
            _data = new char[initlen + 1]{};
        }
        _len = initlen;
        _free = 0;
        if (str && initlen) {
            memcpy(_data, str, initlen);
        }
        _data[initlen] = '\0';
    }

    void sedis::SdsHdr::resize(const int size) {
        if (size < 0) {
            _len = 0;
            _free = 0;
            delete [] _data;
            _data = nullptr;
            return;
        }
        if (_len > size) {
            _len = size;
        }
        _free = size - _len;
        auto oldData = _data;
        //加一是为了给末尾的\0存放位置
        _data = new char[size + 1];
        memcpy(_data, oldData, _len + 1);
        delete [] oldData;
    }

    void sedis::SdsHdr::add(const char *str) {
    }

    int sedis::SdsHdr::size() const { return _len + _free; }
} // againstsky
