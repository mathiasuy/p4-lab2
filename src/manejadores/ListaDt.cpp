#include "ListaDt.h"


    template <typename K, typename T>
    void Util::ListaDt<K,T>::add(T t){
        this->_map[t.getID()] = t;
    }

    template <typename K, typename T>
    void Util::ListaDt<K,T>::start(){
        this->i = this->_map.begin();
    };

    template <typename K, typename T>
    bool Util::ListaDt<K,T>::end(){
        return this->i != this->_map.end();
    };

    template <typename K, typename T>
    T& Util::ListaDt<K,T>::getElement(){
        return this->i->second;
    };

    template <typename K, typename T>
    void Util::ListaDt<K,T>::next(){
        this->i++;
    };

    template <typename K, typename T>
    ostream& operator<<(ostream& os, Util::ListaDt<K,T>& dt)
    {
        dt.start();
        string st = "";
        while (dt.end()){
            st += dt.getElement().toString();
            dt.next();
        }
        os << st;
        return os;
    }
