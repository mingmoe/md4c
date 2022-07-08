
#include <md4c-html.h>
#include <sstream>


#ifdef _MSV_VERSION
    #define PORT_PUBLIC_API __declspec(dllexport)
#else
    #define PORT_PUBLIC_API
#endif

namespace{
    void append(const char* text,MD_SIZE size,void* ptr){
        auto os = reinterpret_cast<std::ostringstream*>(ptr);

        std::string_view view{text,size};

        (*os) << view;
    }
}

extern "C" {
PORT_PUBLIC_API int md4c_csharp_to_html(
    const char* text,
    unsigned size,
    int parse_flags,
    int render_flags,
    void(*callback)(const char* text,unsigned long long size)){

        std::ostringstream strs{};

        auto result = md_html(text,size,&append,&strs,parse_flags,render_flags);

        auto str = strs.str();

        callback(str.c_str(),str.size());

        return result;
    }
}
