#include <Arduino.h>
#include "pagecontroller.h"
#include "sensorpage.h"
PageController::PageController(){
    //TO DO: FILL UP PAGE CONTAINER
    std::string html = "<h1>Hello from ESP8266 Web Server!</h1>";
    html += "<p><a href=\"/link1\">Go to Link 1</a></p>";
    html += "<p><a href=\"/link2\">Go to Link 2</a></p>";
    mPages["/"]=std::make_unique<Page>( Page(html) );
    mPages["/link1"]=std::make_unique<Page>( Page("<h2>This is Link 1 Page</h2><a href=\"/\">Back to Home</a>") );
    //mPages["/link2"]=Page("<h2>This is Link 2 Page</h2><a href=\"/\">Back to Home</a>");
    mPages["/link2"]=std::make_unique<SensorPage>( SensorPage() );
}

const Page &PageController::getPage(std::string request) const
{
    Serial.println("PageController::getPage(std::string request)");
    static const Page page404("error 404 file not found.",404);
    auto it = mPages.find(request);
    if (it != mPages.end())
    {
        Serial.println("page found");
        return* it->second;
    }
    return page404;
}