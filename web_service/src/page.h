#ifndef PAGE_H
#define PAGE_H
#include <string>
class Page{
public:
    Page(std::string content="",int code=200); //добавить код в класс
    virtual const std::string& getContent() const;
    int getCode() const;
protected:
    std::string mContent; 
    int mCode;
};

#endif
