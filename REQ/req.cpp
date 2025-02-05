#include <iostream>
#include <thread>
#include <vector>
#include <curl/curl.h>

void send_post_request(const std::string& url, const std::string& json_data) {
    CURL* curl;
    CURLcode res;
    struct curl_slist* headers = NULL;

    curl = curl_easy_init();
    if (curl) {
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data.c_str());

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Request failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
}

int main() {
    std::string url = "https://menuapp-server.onrender.com/api/menu-manager/menu/add-menu"; // Replace with your actual URL
    std::string json_data = "{"menuName": "ASNBBWIFBUFEOUFEIBUF4LIB4BI4TVI4TIVT4IUITIUTIUG3TIUT3IUT3IU", "description": "AS"}";
    
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(send_post_request, url, json_data);
    }
    
    for (auto& thread : threads) {
        thread.join();
    }
    
    return 0;
}
