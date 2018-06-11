#include "../../include/manejadores/ListaDt.h"


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
     string Util::ListaDt<K,T>::toString(){
        typename map<K,T>::iterator it = _map.begin();
        string st="";
        while (it != _map.end()){
            st += it->second.toString();
            st += "\n";
            it++;
        }
        return st;
     }

template <typename K, typename T>
     int Util::ListaDt<K,T>::size(){
      return _map.size();
     }


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
