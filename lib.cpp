
#include <md4c-html.h>
#include <sstream>


#ifdef WIN32
    #define EXPORT_PUBLIC_API __declspec(dllexport)
#else
    #define EXPORT_PUBLIC_API
#endif

namespace{
    void append(const char* text,MD_SIZE size,void* ptr){
        auto func = reinterpret_cast<void(*)(const char* text,unsigned int size)>(ptr);

        func(text,size);
    }
}

extern "C" {
    EXPORT_PUBLIC_API int md4c_csharp_to_html(
    const char* text,
    unsigned size,
    int parse_flags,
    int render_flags,
    void(*callback)(const char* text,unsigned int size)){
        auto result = md_html(text,size,&append,callback,parse_flags,render_flags);

        return result;
    }

    EXPORT_PUBLIC_API int md4c_csharp_get_version(){
        return MD4CSHARP_VERSION;
    }
}
