class LRUCache
{
    
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> key_ad;
    
    void refreshPosition(int key,int value){
        cache.erase(key_ad[key]);
        cache.push_front({key,value});
        key_ad[key]=cache.begin();
    }
    int capacity;
    
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        capacity=cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(key_ad.find(key)!=key_ad.end()){
            refreshPosition(key,(*key_ad[key]).second);
            return(*key_ad[key]).second;
        }
        return(-1);
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if(key_ad.find(key)!=key_ad.end())
            refreshPosition(key,value);
        else{
            cache.push_front({key,value});
            key_ad[key]=cache.begin();
            if(key_ad.size()>capacity){
                key_ad.erase(cache.back().first);
                cache.pop_back();
            }
        }

        
    }
};