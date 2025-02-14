class ProductOfNumbers {
public:
    int count = 0;
    int prod = 1;
    vector<int> pref;

    ProductOfNumbers() {
        pref.push_back(1); 
    }
    
    void add(int num) {
        if (num == 0) {
            prod = 1;
            count = 0;
            pref.clear();
            pref.push_back(1); 
        } else {
            prod *= num;
            count++;
            pref.push_back(prod);
        }
    }
    
    int getProduct(int k) {
        if (k > count) {  
            return 0;
        }
        int n = pref.size();
        return pref[n - 1] / pref[n - k - 1]; 
    }
};
