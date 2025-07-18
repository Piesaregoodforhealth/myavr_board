#include "page.h"
Page::Page(std::string content,int code){
mContent = content;
mCode = code;
}
const std::string& Page::getContent() const{
   return mContent;
}
int Page::getCode() const{
   return mCode;
}