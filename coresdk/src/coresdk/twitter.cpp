//
//  twitter.cpp
//  splashkit
//
//  Created by Jake Renzella on 19/09/2016.
//  Copyright © 2016 Andrew Cain. All rights reserved.
//
#include "twitter.h"
#include "twitter_driver.h"
#include "web.h"
#include "json.h"

#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <vector>

namespace splashkit_lib
{
    /*
    string generate_signature()
    {
        map<string, string> parameters_map;
        string result = "";
        
        json signature = create_json("twitter signature");
        
        json_add_string(signature, "http_method", "POST");
        json_add_string(signature, "http_url", "https://api.twitter.com/1/statuses/update.json");
        
        parameters_map.insert({url_encode("oauth_signature_method"), url_encode("HMAC-SHA1")});
        parameters_map.insert({url_encode("status"), url_encode("Hello Ladies + Gentlemen, a signed OAuth request!")});
        parameters_map.insert({url_encode("include_entities"), url_encode("true")});
        parameters_map.insert({url_encode("oauth_consumer_key"), url_encode("xvz1evFS4wEEPTGEFPHBog")});
        parameters_map.insert({url_encode("oauth_nonce"), url_encode("kYjzVBB8Y0ZFabxSWbWovY3uYSQ2pTgmZeNu2VS4cg")});
        parameters_map.insert({url_encode("oauth_signature_method"), url_encode("HMAC-SHA1")});
        parameters_map.insert({url_encode("oauth_timestamp"), url_encode("1318622958")});
        parameters_map.insert({url_encode("oauth_token"), url_encode("370773112-GmHxMAgYyLbNEtIKZeRNFsMKPR9EyMZeS9weJAEb")});
        parameters_map.insert({url_encode("oauth_version"), url_encode("1.0")});
        
        for (map<string, string>::iterator i = parameters_map.begin(); i != parameters_map.end(); i++)
        {
            result += i->first + "=" + i->second;
            if (parameters_map.rbegin()->first != i->first)
            {
                result += "&";
            }
        }
        
        json_add_string(signature, "param_collection", result);
        
        string http_method = json_read_string(signature, "http_method");
        string http_url = url_encode(json_read_string(signature, "http_url"));
        string parameter_string = url_encode(json_read_string(signature, "param_collection"));
        
        string signature_base_string = http_method + "&" + http_url + "&" + parameter_string;

        string consumer_secret = "kAcSOqF21Fu85e7zjz7ZN2U4ZRhfV3WpwPAoE3Z7kBw";
        string oath_token_secret = "LswwdoUaIvS8ltyTt5jkRh4J50vUPVVHtR2YPi5kE";
        
        string signing_key = url_encode(consumer_secret) + "&" + url_encode(oath_token_secret);

        std::string sha1hmac = hmac< SHA1 >(signature_base_string, signing_key);
        char* sha1hmac_hex_decoded = hextostr(sha1hmac);

        int size = static_cast<int>(strlen(sha1hmac_hex_decoded));

        auto encoded_result = base64_encode((unsigned const char*)sha1hmac_hex_decoded, size);

        return encoded_result;
    }
    
    void generate_header(json parameters)
    {
        json header = create_json("twitter header");
        json_add_string(header, "oauth_consumer_key", "xvz1evFS4wEEPTGEFPHBog");    //consumer key from twitter app api
        json_add_string(header, "oauth_nonce", "xvz1evFS4wEEPTGEFPHBog");           //Uniquely generate this ourselves
        json_add_string(header, "oauth_signature", generate_signature());           //The signature beast
    }
    
    void authenticate()
    {
        
    }
    
    void new_tweet(string status)
    {
        json http_request = create_json("http request");
        
        json_add_string(http_request, "status", status);
        json_add_string(http_request, "url", "https://api.twitter.com/1/statuses/update.json");
        
    
       // response = http_post("https://api.twitter.com/1.1/statuses/update.json?status=Posting%20from%20%40SplashKit&display_coordinates=false HTTP/1.1", 8080, string body);
    }
     */

    void new_tweet(string status)
    {
        stringstream ss;

        string content = "status=jakeandjames";
        string url = "https://api.twitter.com/1.1/statuses/update.json";

        vector<string> headers;
        headers.push_back("Authorization: OAuth oauth_consumer_key=\"VlU5u3eZD8O9FLLjCJ7X7SZCm\", "
                                  "oauth_nonce=\"2f51578d75e905ec9da75bfadb0f894c\", "
                                  "oauth_signature=\"623Ji28W1v4eN6FIOzJhxobNvlo%3D\", "
                                  "oauth_signature_method=\"HMAC-SHA1\", "
                                  "oauth_timestamp=\"1474457494\", "
                                  "oauth_token=\"777822290318757888-ZTefOHbqKd1huzc7cf5BLDZwfT36rgG\", "
                                  "oauth_version=\"1.0\"");
        headers.push_back("Content-Type: application/x-www-form-urlencoded");

        http_response response = http_post(url, 443, content, headers);

        cout << "response is: " << http_response_to_string(response) << endl;
    }
}
