#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <gumbo.h>

using namespace std;


size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

int main() {
    CURL* curl;
    CURLcode res;

    
    curl = curl_easy_init();
    if (!curl) {
        cerr << "Failed to initialize libcurl." << endl;
        return 1;
    }

    
    string url = "https://example.com/products";

   
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    string html_content; 

    
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html_content);

    
    res = curl_easy_perform(curl);

   
    if (res != CURLE_OK) {
        cerr << "Failed to fetch URL: " << curl_easy_strerror(res) << endl;
        curl_easy_cleanup(curl);
        return 1;
    }

    
    curl_easy_cleanup(curl);

    
    GumboOutput* output = gumbo_parse(html_content.c_str());
    if (!output) {
        cerr << "Failed to parse HTML using Gumbo Parser." << endl;
        return 1;
    }

    
    cout << "HTML Content:" << endl;
    cout << html_content << endl;

   
    gumbo_destroy_output(&kGumboDefaultOptions, output);

    return 0;
}
