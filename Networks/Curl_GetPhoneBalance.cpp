/*
#include "curl.h"

size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
   ((std::string*)userp)->append((char*)contents, size * nmemb);
   return size * nmemb;
}

std::string GetBalance(const std::string& phone, const std::string& pass)
{
   CURL *curl;
   CURLcode res;
   std::string readBuffer;

   curl_global_init(CURL_GLOBAL_DEFAULT);

   curl = curl_easy_init();
   if (curl)
   {
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);

      std::string request = "https://lk.ssl.mts.ru/?from=login.mts.ru";
      curl_easy_setopt(curl, CURLOPT_URL, request.c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, misc::writeCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);
      if (res != CURLE_OK)
      {
         std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
      }
      curl_easy_cleanup(curl);
   }

   curl_global_cleanup();

   auto posBegin = readBuffer.find("<text>");
   if (posBegin != -1)
   {
      auto posEnd = readBuffer.find("</text>");
      if (posEnd != -1)
      {
         std::string sTranslation = readBuffer.substr(posBegin + sizeof("<text>") - 1, posEnd - posBegin - sizeof("</text>") + 2);
         return sTranslation;
      }
   }

   return "";
}*/
