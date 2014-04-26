#ifndef HEAP_H
#define HEAP_H

#include "HeapADT.h"
#include<iostream>
#include<math.h>
#include<QString>


using namespace std;

template<typename E>

class HeapCDT : public HeapADT<E>
{

public:

    E *Heap;
    int maxsize;
    int position;
    int maxlevel;
    int level;

    HeapCDT(E value, int size){
        maxsize = size;
        Heap = new E[maxsize];
        maxlevel = 0;
        Heap[0] = value;
    }

    HeapCDT(int size, E *old){
        maxsize = size;
        Heap = new E[maxsize];
        Heap = old;
    }

    void insert(const E& it){
        Heap[maxsize++] = it;
    }

    void repeatString(char *str, int num){
        for(int i = 0; i < num; i++){
            cout << str;
        }
    }

    void printHeap(){
        MaxLevel();
        int tmp = 2;
        level = 1;
        int qtd;
        if(maxsize > 7){
            qtd = ((pow(2,(maxlevel)*2)- 13));
        }
        else{
            qtd = ((pow(2,(maxlevel)*2)- 2));
        }

        if(maxsize < 16){
            for(int i = 0; i < maxsize; (i++)){
                if(i == 0 || i == 11){
                    repeatString(" ",(qtd/pow(2,level)));
                    cout << Heap[i];
                    tmp++;
                }
                else if(pow(2,level) < tmp){

                    level++;
                    cout << endl << endl;
                    repeatString(" ",(qtd/pow(2,level)));
                    cout << Heap[i];
                    tmp++;

                }
                else{
                    repeatString(" ",(qtd/pow(2,level))*2);
                    cout << Heap[i];
                    tmp++;
                }

            }
        }
        else{
            for(int i = 0; i < maxsize; (i++)){

                cout << Heap[i] << " ";

            }
        }

        cout << endl ;
    }
    int parent(int pos) const{
        if(pos % 2 != 0){


            return ((pos)/2);


        }else{

            return ((pos)/2)-1;

        }
    }
    int righ(int pos) const{

        return  ((pos + 1)*2);

    }
    int left(int pos) const{

        return ((pos+1)*2)-1;

    }
    void backof(int pos = 0){

        Heap[pos] =Heap[pos + 1];
        for(int i = pos + 1; i < maxsize - 1; i++){

            Heap[i] = Heap[i + 1];

        }

    }

    E removefirst(){

        E tmp;
        tmp = Heap[0];
        backof();
        maxsize--;

        return tmp;

    }
    int size() const{

        return maxsize;

    }
    E remove(int pos){
        pos = pos - 1;
        E tmp;
        if(pos < maxsize-1 && pos >= 0){

            tmp = Heap[pos];
            backof(pos);
            maxsize--;

            return tmp;

        }
        else if(pos == maxsize - 1){

            tmp = Heap[pos];
            maxsize--;

            return tmp;


        }
        else{

            cout << "erro" << endl;

        }
        return -1;
    }
    void MaxLevel(){

        int tmp = 1;
        maxlevel = 1;
        for(int i = 1; i < maxsize; (i++)){
            if(pow(2,maxlevel) < tmp){
                maxlevel++;
                tmp = 1;
            }
            tmp++;
        }

    }
    E getValue(int pos){
        return Heap[pos];
    }

    void heapfy(int pos){
        MaxLevel();
        int l,r,maior;
        l = left(pos);
        r = righ(pos);

        if(isLeaf(pos) == 0){
            if ((l <= maxsize) && (Heap[l] > Heap[pos])){
                maior = l;
            }else{
                maior = pos;
            }
            if ((r <= maxsize) && (Heap[r] > Heap[maior])){
                maior = r;
            }
            if (maior != pos)
            {
                swapper(pos,maior);
                heapfy(maior);
            }

        }
    }

    void buildMaxHeap(){
        for (int i = (maxsize/2) - 1; i >= 0; i--)
            heapfy(i);
    }

    void swapper(int pos, int pos2){
        int tmpp;
        tmpp = Heap[pos];
        Heap[pos] = Heap[pos2];
        Heap[pos2] = tmpp;
    }
    bool isLeaf(int pos) const{
        int tmp = 2;
        int numlevel = 1;
        if(pos != 0){
            for(int i = 0; i < maxsize; (i++)){
                if(i < pos){
                    if(pow(2,numlevel) < tmp){
                        numlevel++;
                        tmp = 1;
                    }
                    else{
                        tmp++;
                    }
                }
                else{
                    break;

                }


            }


            if(numlevel  == maxlevel){
                return 1;
            }
            else {
                return 0;
            }
        }
        else{
            return 0;
        }
    }
};

#endif
