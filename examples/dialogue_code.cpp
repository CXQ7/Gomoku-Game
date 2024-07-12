#include "openai.hpp"
#include "nlohmann/json.hpp"

#include <bits/stdc++.h>

using json = nlohmann::json;

int main() {
    char *api_key = getenv("OPENAI_API_KEY");
    openai::start(api_key,"",true,"https://agino.me/"); // Will use the api key provided by `OPENAI_API_KEY` environment variable
    // openai::start("your_API_key", "optional_organization"); // Or you can handle it yourself
    
    int k=0;
    std::string q[100], end = "end", now, ans, former_ans = "the former answers are:", base = " Base on the former text answer the following question:";
    do {
        getline(std::cin, q[k++]);
        if(q[k-1] == end) break;
        now = "";
        now.append(former_ans).append(base).append(q[k-1]);
        json post = {
            {"model", "gpt-3.5-turbo"},
            {"messages", {
                {
                    {"role", "user"},
                    {"content", now}
                }
            }}
        };
        auto completion = openai::chat().create(post); // Using user-defined (raw) string literals
        //std::cout << now << std::endl;
        ans = (std::string)completion.at("choices")[0]["message"]["content"];
        former_ans.append(ans).append("/");
        std::cout<<ans<<std::endl;
    }while(q[k-1] != end);
}