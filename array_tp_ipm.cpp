#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

template<class T>
class ArrayList{
    private:
        unsigned int size = 0;
        T* arr;

        void swap(T& arg1, T& arg2){
            T tmp = arg1;
            arg1 = arg2;
            arg2 = tmp;
        }

        void s_append(const T arg){
            T* tmp = new T[size + 1];
            for(int i = 0; i < size; i++) tmp[i] = arr[i];
            tmp[size] = arg;
            size++;
            delete[] arr;
            arr = tmp; 
        }

        void s_pop(const T arg){
            int target = -1;
            for(int i = 0; i < size; i++){
                if(arr[i] == arg){
                    target = i;
                    break;
                }
            }
            if(target == -1) return;
            T* tmp = new T[size - 1];
            unsigned int tmpIndex = 0;
            for(int i = 0; i < size; i++){
                if(i != target){
                    tmp[tmpIndex++] = arr[i];
                }
            }
            size--;
            delete[] arr;
            arr = tmp;
        }

    public:
        ArrayList() : size(0), arr(nullptr){}

        template <typename... Args>
        ArrayList(const Args... args){
            size = sizeof...(args);
            arr = new T[size];
            int i = 0;
            ((arr[i++] = args), ...);
        }

        ArrayList(const ArrayList& other) {
            size = other.size;
            if (other.arr) {
                arr = new T[size];
                for (int i = 0; i < size; i++) arr[i] = other.arr[i];
            } else {
                arr = nullptr;
            }
        }

        ~ArrayList(){
            delete[] arr;
        }

        const int getTypeID(){
            if(typeid(T) == typeid(int))    return 1;
            if(typeid(T) == typeid(float))  return 2;
            if(typeid(T) == typeid(double)) return 3;
            if(typeid(T) == typeid(bool))   return 4;
            if(typeid(T) == typeid(char))   return 5;
            if(typeid(T) == typeid(string)) return 6;
                                            return 0;
        }

        const int getSize(){
            return size;
        }

        const T* getArray() {
            return arr;
        }


        //contain function return the amount of specific existed instances
        //@param arg is a required parameter to search
        unsigned int contain(const T arg){
            unsigned int count = 0;
            for(int i = 0; i < size; i++){
                if(arr[i] == arg) count++;
            }
            return count;
        }

        //indexOf function returns the index where the code first encounters its parameter
        //@param arg is a required parameter to search.
        //@note If argument isn't existed in array, function will return -1.
        int indexOf(const T arg){
            for(int i = 0; i < size; i++){
                if(arr[i] == arg) return i;
            }
            return -1;
        }

        // replace function is to overwrite first occurrence of specific instance.
        // @param arg1 is required parameter to replace
        // @param arg2 is required parameter being replaced
        void replace(const T arg1, const T arg2){
            int index = indexOf(arg2);
            if(index == -1) return;
            arr[index] = arg1; 
        }

        // Simple append function add more elements
        // @param args are instances inserted after existed elements within array
        template <typename... Args>
        void append(const Args... args){
            (s_append(args), ...);
        }

        // Simple pop function removes the existed elements within array.
        // @param args are to search any existed elements as targets to remove from array.
        // @note Element is removed one from specific existed elements within array by passing argument.
        // It means that if there are two elements same things, can only remove once a time, unless insert another exact same thing.
        // It only removes element where the code first encounters.
        template <typename... Args>
        void pop(const Args... args){
            if(size == 0) return;
            (s_pop(args), ...);
        }

        void omitByIndex(const int index){
            T* tmp = new T[size - 1];
            int tmp_index = 0;
            for(int i = 0; i < size; i++){
                if(i != tmp_index) tmp[tmp_index++] = arr[i];
            }
            size--;
            delete[] arr;
            arr = tmp;
        }

        /*
        *! \brief Sorting Items through array.
        *
        * @param ascending boolean argument is assigned to true, result returns from the lowest to the highest. Or if false, returns from the highest to the lowest.
        * @param maniputation integer argument is assigned to this given integer, result as follows:
        ** 0 : Sorted array by numbers, chars or bools
        ** 1 : Sorted array by first character inside string
        ** 2 : Sorted array by length of string
        * @note No arguments to this type of function, the function will use the default arguments.
        * @warning Define its arguments correctly to its type!
        */
        void sort(const bool ascending = true, const int manipulation = 0){
            for(int i = 0; i < size - 1; i++){
                for(int j = 0; j < size - i - 1; j++){
                    
                    bool shouldSwap = false;
                    
                    if(ascending){
                        // 1. General Sort for everything (Numbers, chars, bools, and alphabetical strings)
                        if(manipulation == 0) {
                            if (arr[j] > arr[j + 1]) shouldSwap = true;
                        }
                        // 2. String-specific manipulations guarded by C++17 compile-time checks
                        if constexpr (std::is_same_v<T, std::string>) {
                            if(manipulation == 1) { // Sort by first character ASCII value
                                if(int(arr[j][0]) > int(arr[j + 1][0])) shouldSwap = true;
                            }
                            if(manipulation == 2) { // Sort by length of string
                                if(arr[j].length() > arr[j + 1].length()) shouldSwap = true;
                            }
                        }
                    }
                    else { // Descending sort
                        if(manipulation == 0) {
                            if(arr[j] < arr[j + 1]) shouldSwap = true;
                        }
                        if constexpr (std::is_same_v<T, std::string>) {
                            if(manipulation == 1) {
                                if(int(arr[j][0]) < int(arr[j + 1][0])) shouldSwap = true;
                            }
                            if(manipulation == 2) {
                                if(arr[j].length() < arr[j + 1].length()) shouldSwap = true;
                            }
                        }
                    }

                    if(shouldSwap) {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }

        ArrayList& operator=(const ArrayList& other) {
            if (this != &other) {
                delete[] arr;
                size = other.size;
                if (other.arr) {
                    arr = new T[size];
                    for (int i = 0; i < size; i++) arr[i] = other.arr[i];
                } else {
                    arr = nullptr;
                }
            }
            return *this;
        }

        template <typename C>
        friend ostream& operator<<(ostream& output, const ArrayList<C>& arr);
};

template <typename C>
ostream& operator<<(ostream& output, const ArrayList<C>& arr){
    output << "[ ";
    for(int i = 0; i < arr.size; i++){
        if(i == arr.size - 1) output << arr.arr[i];
        else output << arr.arr[i] << ", ";
    }
    output << " ]";
    return output;
}

int main(){
    ArrayList<int> b;
    ArrayList<string> c = {"hello", "yes", "ok"};
    cout << c << endl;
    b.append(43, 45, 90, 34, 23);
    b.replace(43, 90);
    
    ArrayList<string> str;
    str.append("Mengying", "Hello");
    
    cout << "Original: " << b << endl;
    cout << "Original: " << str << endl;
    b.sort(true, 0);
    str.sort(true, 2);
    cout << "Sorted:   " << b << endl;
    cout << "Sorted:   " << str << endl;
    str.pop("Hello");
    b.pop(43);
    cout << "Deleted:   " << str << endl;
    cout << "Deleted:   " << b << endl;

    return 0;
}
