class MedianFinder {
public:
    multiset<int> st;

    MedianFinder() {
    }

    void addNum(int num) {
        st.insert(num);
    }

    double findMedian() {
        int n = st.size();

        auto it = st.begin();

        advance(it, n / 2);

        if(n % 2)
            return *it;

        int right = *it;
        it--;
        int left = *it;

        return (left + right) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */