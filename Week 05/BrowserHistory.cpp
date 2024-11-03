// https://leetcode.com/problems/design-browser-history/description/?envType=problem-list-v2&envId=doubly-linked-list

struct Website
{
    string url;
    Website* prev = nullptr;
    Website* next = nullptr;

    Website(string url): url(url)
    {}
};

class BrowserHistory 
{
    Website* homepage=nullptr;
    Website* current=nullptr;
    int openTabs=0;
public:
    BrowserHistory(string homepage) 
    {
        this->homepage=new Website(homepage);
        this->current=this->homepage;
        openTabs++;
    }
    
    void visit(string url) 
    {
        Website* newSite=new Website(url);
        newSite->prev=current;
        current->next = newSite;
        current=current->next;
        openTabs++;
    }
    
    string back(int steps) 
    {
        int counter=0;
        while(current && current->prev && counter++<steps)
        {
            current=current->prev;
        }    
        return current->url; 
    }
    
    string forward(int steps) 
    {
        int counter=0;
        while(current && current->next && counter++<steps)
        {
            current=current->next;
        }    
         return current->url; 
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
