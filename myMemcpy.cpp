void* myMemcpy(void* dest, const void* src, size_t n){
    if(dest == nullptr || src == nullptr) return nullptr;
    void* ret = dest;
    if(dest > src && (char*)dest < (char*)src + n){
        src = (char*)src + n - 1;
        dest = (char*)dest + n - 1;
        while(n--){
            *(char*)dest = *(char*)src;
            dest = (char*)dest - 1;
            src = (char*)src - 1;
        }
    }else{
        while(n--){
            *(char*)dest = *(char*)src;
            dest = (char*)dest + 1;
            src = (char*)src + 1;
        }
    }
    return ret;
}