#include "openai.hpp"
#include "nlohmann/json.hpp"

#define BOARD_SIZE 15

#include <bits/stdc++.h>

using json = nlohmann::json;
using namespace std;

int board[BOARD_SIZE][BOARD_SIZE] = {0};

int main() {
    char *api_key = getenv("OPENAI_API_KEY");
    openai::start(api_key,"",true,"https://agino.me/");  // Will use the api key provided by `OPENAI_API_KEY` environment variable
    // openai::start("your_API_key", "optional_organization"); // Or you can handle it yourself

    std::string post, prompt = "Please use a 'O' to replace a '.', and reply me with a board represent like me.", rule = "We are going to play gomoku, I have played the chess 'X' and it's your turn to place one chess 'O', the following content showing the board:";

    json post = {
            {"model", "gpt-3.5-turbo"},
            {"messages", {
                {
                    {"role", "user"},
                    {"content", "hello"}
                }
            }}
        };
        auto completion = openai::chat().create(post); // Using user-defined (raw) string literals

        std::cout<<completion.at("choices")[0]["message"]["content"].is_string();
}
