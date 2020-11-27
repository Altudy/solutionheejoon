class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int len = l1 + l2;

        double ans(0.0);

        // if one vector is empty
        if (l1 == 0) {
            if (l2 % 2 == 0) { ans = nums2[l2 / 2 - 1] + nums2[l2 / 2]; ans /= 2; }
            else ans = nums2[l2 / 2];
            return ans;
        }
        else if (l2 == 0) {
            if (l1 % 2 == 0) { ans = nums1[l1 / 2 - 1] + nums1[l1 / 2]; ans /= 2; }
            else ans = nums1[l1 / 2];
            return ans;
        }
        int idx1(0), idx2(0);
        int center = len / 2;
        cout << "center : " << center << endl;

        if (len % 2 != 0) // odd
        {
            while (center--)
            {
                if (nums1[idx1] <= nums2[idx2]) idx1++;
                else idx2++;
                if (idx1 >= l1) {
                    idx2 += center;
                    ans += nums2[idx2];
                    break;
                }
                else if (idx2 >= l2) {
                    idx1 += center;
                    ans += nums1[idx1];
                    break;
                }
            }
            cout << "idx1 : " << idx1 << " idx2 : " << idx2 << endl;
            if (!ans) ans += min(nums1[idx1], nums2[idx2]);
        }
        else // even
        {
            center -= 1;
            while (center--)
            {
                if (nums1[idx1] <= nums2[idx2]) idx1++;
                else idx2++;
                if (idx1 >= l1) {
                    idx2 += center;
                    ans += nums2[idx2] + nums2[idx2 + 1];
                    break;
                }
                else if (idx2 >= l2) {
                    idx1 += center;
                    ans += nums1[idx1] + nums1[idx1 + 1];
                    break;
                }
            }
            cout << "idx1 : " << idx1 << " idx2 : " << idx2 << " ans : " << ans << endl;
            if (!ans)
            {
                if (nums1[idx1] <= nums2[idx2]) {
                    ans += nums1[idx1];
                    idx1++;
                }
                else {
                    ans += nums2[idx2];
                    idx2++;
                }

                cout << "idx1 : " << idx1 << " idx2 : " << idx2 << " ans : " << ans << endl;
                if (idx1 >= l1) {
                    ans += nums2[idx2];
                }
                else if (idx2 >= l2) {
                    ans += nums1[idx1];
                }
                else
                    ans += min(nums1[idx1], nums2[idx2]);
                cout << "idx1 : " << idx1 << " idx2 : " << idx2 << " ans : " << ans << endl;
            }
            ans /= 2;
        }
        return ans;
    }
};

////////////////////////////////////////////////
/* best solution 1

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int tot = m+n;
        
        if(tot % 2 == 0){
            int l = kth(nums1,0,m-1,nums2,0,n-1,tot/2);
            
            int r = kth(nums1,0,m-1,nums2,0,n-1,tot/2+1);
           
            return (l+r)/2.0;
        }else{
            return kth(nums1,0,m-1,nums2,0,n-1,tot/2+1);
        }
        
    }
    
    
    int kth(vector<int>&nums1, int st1, int ed1, vector<int>&nums2, int st2, int ed2, int k){
        int m = ed1-st1+1;
        int n = ed2-st2+1;
        
        //keep the nums2 as the shorter one, so the base case can work correctly.
        if(n > m) return kth(nums2,st2,ed2,nums1,st1,ed1,k);
        //two base case, if shorter one with 0 size, return it directly.
        if(n == 0) return nums1[st1+k-1];
        //if kth smaller is 1, then it must be the min of the st1 or st2 ele.
        if(k == 1) return min(nums1[st1],nums2[st2]);
        
    
        int j = min(n,k/2);
        int i = k - j;
        
        if(nums1[st1+i-1] > nums2[st2+j-1]){
            //k-j, since nums2's left part is the smallest and removed, so kth smallest need to remove this section, since it must be within the current k smallest section.
            return kth(nums1,st1,st1+i-1,nums2,st2+j,ed2,k-j);
        }
        else{
           //k-i, since nums1's left part is the smallest and removed, so kth smallest need to remove this section, since it must be within the current k smallest section. 
            return kth(nums1,st1+i,ed1,nums2,st2,st2+j-1,k-i);
        }
    }
};

*/

/* best solution 2

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        bool odd = ((s1 + s2) % 2);
        int midpos = (s1 + s2) / 2;
        int c1 = 0 , c2 = 0;
        int v1 = 0, v2 = 0;
        int prev_val, val = -1;
        while (true) {
            v1 = (c1 < s1) ? nums1[c1] : 99999999;
            v2 = (c2 < s2) ? nums2[c2] : 99999999;
            prev_val = val;
            val = (v1 > v2) ? v2 : v1;
            if (c1 + c2 == midpos) break;
            (v1 > v2) ? ++c2 : ++c1;
        };
        return odd ? val : (val + prev_val) / 2.0;
    }
};

*/



/* best solution 3
// just use merge function
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     
        vector<int> m; 
        int l =nums1.size()+nums2.size();
        m.reserve(l);
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(), back_inserter(m)); // back_inserter는 컨테이너 맨 뒤에 요소를 추가할 수 있도록 iterator를 반환한다.
        return l%2==0 ? ((m[l/2]+m[l/2-1])/2.0) : m[l/2];
    }
};

*/
