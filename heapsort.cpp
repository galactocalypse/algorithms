/*
   @author: galactocalypse
   @date: 02/11/2014

   The code might not be very OOP-sound but that's only because I haven't done 
   much OO programming in C++. Suggestions in structure are welcome!

   What I have done is pretty simple:
   A class Heap implements the max-heap data structure(change the > sign to < 
   in the cmp function to convert this to a min-heap). And is then used to sort 
   an integer array. I have tried to make the code generic but I'm certain there 
   are numerous gaps I've overlooked.

   Problems with indentation are attributed to my unfamiliarity with vim.

   You could use any class instead of int. Just make sure you add the 
   appropriate cmp function.

 */

#include<bits/stdc++.h>
using namespace std;

template <class T>
class Heap{
        private:
                T *arr;
                int size;
        public:

                void swap(T *a, T *b){
                        T c = *a;
                        *a = *b;
                        *b = c;
                }
                Heap(){
                        arr = NULL;
                        size = 0;
                }
                Heap(T* arr, int n){
                        this->arr = arr;
                        this->size = n;
                        build();
                }
                int heapsize(){
                        return this->size;
                }
                int left(int i){
                        if (i*2+1 >= size || i < 0) {
                                return -1;
                        }
                        else {
                                return i * 2 + 1;   
                        }
                }
                int right(int i){
                        if (i < 0 || i*2+2 >= size) {
                                return -1;
                        }
                        else {
                                return i * 2 + 2;
                        }
                }
                bool cmp(const T a, const T b);
                void print_element(T);
                void print(){
                        for (int i = 0; i < size; i++) {
                                print_element(arr[i]);
                                cout << " ";
                        }
                        cout << endl;
                }
                void max_heapify(int i){
                        if (i >= 0 && i < size) {
                                int l = left(i);
                                int r = right(i);
                                int mx = 0;
                                if (r > 0 && cmp(arr[r], arr[l])) {
                                        mx = 2;
                                }
                                else if(l > 0 && cmp(arr[l], arr[i])) {
                                        mx = 1;
                                }

                                if (mx == 1) {
                                        swap(&arr[i], &arr[l]);
                                        max_heapify(l);
                                }
                                else if (mx == 2) {
                                        swap(&arr[i], &arr[r]);
                                        max_heapify(r);
                                }
                        }
                }

                int build(){
                        int lim = 1;
                        while (lim <= size) {
                                lim *= 2;
                        }
                        lim /= 2;
                        for (int i = lim - 2; i >= 0; i--) {
                                max_heapify(i);
                        }
                }
                T extract_max(){
                        if (size > 0) {
                                int mx = arr[0];
                                swap(&arr[0], &arr[size - 1]);
                                size--;
                                max_heapify(0);
                                return mx;
                        }
                        else {
                                return -1;
                        }
                }
                T get_max(){
                        if(size > 0){
                                return arr[0];
                        }
                        else {
                                return -1;
                        }
                }
                //ugly hack to allow printing of heap elements after all elements have been extracted
                void force_reset_size(int n) {
                        this->size = n;
                }
};

template<> bool Heap<int>::cmp(const int a, const int b){
        return a > b;
}
template<> void Heap<int>::print_element(int x){
        cout << x;
}
int main(void){
        int n;
        cin >> n;
        int *arr = (int*)malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++) {
                cin >> arr[i];
        }
        Heap<int> *h = new Heap<int>(arr, n);
        for (int i = 0; i < n; i++) {
                h->extract_max();
        }
        h->force_reset_size(n);
        h->print();
        return 0;
}

