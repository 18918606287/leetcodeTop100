int _=[](){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
	}();
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        this->m = multiset<int>();
    }
    
    void addNum(int num) {
        if(m.empty()){
            m.insert(num);
            r = m.begin();
            l = m.begin();
        } else {
            m.insert(num);
            if(num >= *r){
                if(r == l) r++;
                else l++;
            } else if(num < *l){
                if(r == l) l--;
                else r--;
            } else {
                r--;
                l++;
            }
        }
    }
    
    double findMedian() {
        return((*r+*l)*1.0/2);
    }
private:
    multiset<int> m;
    multiset<int>::iterator r;
    multiset<int>::iterator l;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
