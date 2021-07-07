class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> u;
        for(int i=0;i<nums2.size();i++){
            if(s.empty() or nums2[i] < s.top()) //agar top se chota hai to push karo
                s.push(nums2[i]);
            else{
                //jab tak wo number top se chota na ho jaye tab tak stack se elements pop karte raho
                while(!s.empty() and nums2[i] > s.top()){
                    u[s.top()] = nums2[i];
                    s.pop();
                }
                s.push(nums2[i]);
            }
        }
        for(int i=0;i<nums1.size();i++){
            if(u[nums1[i]])
                nums1[i] = u[nums1[i]];
            else
                nums1[i] = -1;
        }
        return nums1;
    }
};