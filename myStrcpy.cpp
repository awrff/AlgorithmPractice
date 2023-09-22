char* myStrcpy(char* dest, const char* src){
    if(dest == nullptr || src == nullptr) return nullptr;
    char* destCopy = dest;
    while((*dest++ = *src++) != '\0') ;
    return destCopy;
}