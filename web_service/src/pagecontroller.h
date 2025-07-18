#ifndef PAGECONTROLLER_H
#define PAGECONTROLLER_H
#include <string>
#include <map>
#include <memory>
#include "page.h"
class PageController{
public:
    PageController();
    const Page& getPage(std::string request) const;
private:
    std::map<std::string,std::unique_ptr <Page>> mPages;
};

#endif
