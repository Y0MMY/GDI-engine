// #include <map>
 
// ////~~~~~~~~~~~~~~~~~~~~INTERFACES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// template<class TKey, class TValue>
// class Dictionary {
// public:
//     virtual ~Dictionary() = default;
 
//     virtual const TValue &Get(const TKey &key) const = 0;
 
//     virtual void Set(const TKey &key, const TValue &value) = 0;
 
//     virtual void Remove(const TKey &key) = 0;
 
//     virtual bool IsSet(const TKey &key) const = 0;
// };
 
// template<class TKey>
// class NotFoundException : public std::exception {
// public:
//     virtual const TKey &GetKey() const noexcept = 0;
// };
 
// ////~~~~~~~~~~~~~~~~~~~~IMPLEMENTATION~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
// template<class TKey>
// class NotFoundExceptionImpl : public NotFoundException<TKey> {
//     TKey key;
// public:
//     explicit NotFoundExceptionImpl(const TKey &_key) : key(_key) {}
 
//     const TKey &GetKey() const noexcept override {
//         return key;
//     }
 
//     const char *what() const noexcept override {
//         return "No such key in container";
//     }
// };
 
// template<class TKey, class TValue>
// class DictonaryImpl : public Dictionary<TKey, TValue>,
//                       public std::map<TKey, TValue> {
// public:
//     const TValue &Get(const TKey &key) const override {
//         try {
//             return this->at(key);
//         }
//         catch (std::out_of_range &e) {
//             throw NotFoundExceptionImpl(key);
//         }
//     }
 
//     void Set(const TKey &key, const TValue &value) override {
//         this->operator[](key) = value;
//     }
 
//     void Remove(const TKey &key) override {
//         auto it = this->find(key);
//         if (it == this->end())
//             throw NotFoundExceptionImpl(key);
//         this->erase(it);
//     }
 
//     bool IsSet(const TKey &key) const override {
//         return this->count(key);
//     }
// };


#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdio>

#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib,"gdiplus.lib")