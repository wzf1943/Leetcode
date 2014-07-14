//1. Two Sum 
//<1> mapping the num to hash table key:num[] value:i
//<2> create a gap = target - num[i]
//<3> traverse the hashtable by using gap as a key, if find gap is in the hash
//    table. push_back the gap to the end of the result.
class Solution {
    public:
        vector<int> twoSum(vector<int> & num, int target) {
            unordered_map <int, int> mapping;
            vector<int> result;
            for(int i = 0; i < num.size(); i++) {
                mapping[num[i]] = i;
            }

            for(int i = 0; i < num.size(); i++) {
                const int gap = target - num[i];
                if(mapping.find(gap) != mapping.end()) {
                    if(mapping(gap) == 1) continue;
                    result.push_back(i + 1);
                    result.push_back(mapping[gap] + 1);
                    break;
                }
            }

            return result;
        }
};

//2.Median of two sorted arrays
//
class Solution {
    public:
};

//3. Longest Substring without Repeating Characters
//still need figure out how to understand this stuff
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            const int ASCII_MAX = 127;
            int last[ACII_MAX];
            int start = 0;

            memset(last, -1, ASCII_MAX; i++);
            int max_len = 0;

            for(int i = 0; i < s.size(); i++) {
                if(last[s[i] - 'a'] > start) {
                    max_len = max(i - start, max_len);
                    start = last[s[i] - 'a'] + 1;
                }
                last(s[i] - 'a') = i;
            }
            return max((int)s.size() - start; max_len);
        }
};

//4.Add Two Numbers
//(2 -> 4 -> 3) + (5 -> 6 -> 4)
// 7 -> 0 -> 8
class Solution {
    ListNode * addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *prev = & dummy;
        int carry;
        for(ListNode * pa = l1, *pb = l2;
                pa != NULL  || pb != NULL;
                pa = pa == NULL ? NULL : pa -> next,
                pb = pb == NULL ? NULL : pb -> next,
                prev = prev -> next;)
            const int ai = pa == NULL ? 0 : pa -> val;
            const int bi = pb == NULL ? 0 : pb -> val;
            const value = (ai + bi + carry) % 10;
            carry = (ai + bi + carry) / 10;
            prev -> next = new ListNode (value);
    }
    if(carry > 0) 
        prev -> next = new ListNode(carry);
    return dummy.next;
};


//5. Longest Palindrome Substring
// still don't figure out how to implement this probelm
class Solution {
    string longestPalindrome(string) {
        int startIndex = 0;
        int len = 0;
        int sI, eI;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == s[i + 1])
            {
                sI = i;
                eI = i + 1;
                Search(s, sI, eI, len, startIndex);
            }
            sI = i;
            eI = i;
            Search(s, sI, eI, len, startIndex);
        }
        if(len == 0)
            len = s.size();
        return s.substr(startIndex, len);
    }

    void Search(string &s, int sI, int eI, int & len, int & startIndex)
    {
        int step = 1;
        while((sI - step) >= 0 && (eI + step) < s.size())
        {
            if(s[sI - step] != s[eI + step])
            {
                break;
            }
            step++;
        }
        int wid = eI - sI + 2*step -1;
        if(wid > len) 
        {
            len = wid;
            startIndex = sI - step + 1;
        }
    }
};


    }
}

//5.Reverse Integer

class Solution {
    public:
        int reverse(int x){
            int r = 0;
            for(; x; x %= 10) {
                r = r * 10 + x % 10;
            }
            return r;
        }
};

//6.Remove Duplicate of Sorted Array

class Solution {
    public:
        removeDuplicate(int A[], int n) {
            if(n == 0) return 0;
            int index = 0;
            for( int i = 0; i < n; i++) {
            if(A[index] != A[i])
                A[index++] = A[i];
            }
            return index + 1;
        }
};

//7.Remove Duplicate from Sorted Array II
//A[1, 1, 1, 2, 2, 3]
//A[1, 1, 2, 2, 3]
class Solution {
    public:
        int removeDuplicateII(int A[], int n) {
            if(n <= 2) return n;
            int index = 2;
            for(int i = 2; i < n; i++) {
                if(A[i] != A[index - 2]) {
                    A[++index] = A[i];
                }
            }
            return index;
        }
};

//8.Search in Rotated Array 
//Ask ??????
class Solution {
    public:
        int search(int A[], int n, int target){
            int first = 0, last = n;
            while(first != last) {
                const int mid = (first + last) / 2;
                if(A[mid] == target)
                    return mid;
                if(A[first] < A[mid]) {
                    if(A[first] <= targe && target < A[mid]) 
                        last = mid;
                    else 
                        first = mid + 1;
                } else {
                    if(A[mid] < target && target <= A[last - 1]) 
                        first = mid + 1;
                    else
                        last = mid;
                }
            }
                return -1;
        }
};

//9. Rotated Search Array II
//
class Solution {
    public:

};

//10. Longest Consecutive Sequence
//<1> map the num to hash table
//<2> traverse the num from 0 to n
//<3> traverse left and right from each num 
//    find if the number is in the hash table, i
//    if we can find the num in the hash table 
//    which means the sub string is consecutive 
//    then we can add length 1.
class Solution {
    public:
        int longestConsecutive(const vector<int> & num) {
            unordered_map <int, bool> used;
            for(auto i : num) {
                used[i] = false;
            }

            int longest = 0;
            for(auto i : num) {
                if(used[i]) continue;
                int length = 1;
                used[i] = true;
                for(int j = i + 1; used.find(j) != used.end(); ++j) {
                    used[j] = true;
                    ++length;
                }
                for(int j = i - 1; used.find(j) != used.end(); --j) {
                    used[j] = true;
                    ++length;
                }
                longest = max(length, Longest);
            }
            return longest;
        }
};

//11.3 Sum 
//<1> sort
//<2> two pointers find target
//
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int> & num) {
            vector<vector<int>> result;
            //if(num.size() < 3) return false;
            sort(num.begin(), num.end());

            const target = 0;
            int len = num.size();
            
            for(int i = 0; i < len; i++) 
            {
                target = 0 - num[i];
                int start = i + 1, end = len - 1;
                while(start < end) 
                {
                    if(num[start] + num[end] == target) 
                    {
                        vector<int> solution;
                        solution.push_back(num[i]);
                        solution.push_back(num[start]);
                        solution.push_back(num[end]);
                        start++;
                        end--;
                        while(start < end && num[start] == num[start - 1])
                            start++;
                        while(start < end && num[end] == num[end + 1])
                            end--;
                    } else if (num[start] + num[end] < target){
                        start++；
                    } else {
                        end--;
                    }
                    //speed up part
                    if(i < len - 1){
                        while(num[i] == num[i + 1]) 
                            i++;
                    }
                }
                return result;
            }
        }
};

//12.Remove Element 
class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            int index;
            for(int i = n; i < n; i++) {
                if(A[index] == A[i])
                    A[index++] = A[i]
            }
            return index;
        }
}

//13. Next Permutation 

class Solution {
};

//14 Rotate Image
//1 对角线
//2 折叠
class Solution {
    public:
        void Rotate(vector<vector<int>> & matrix) {
            const n = matrix.size();

            for(int i = 0; i < n; i++){ 
                for(int j = 0; j < n - i; j++){
                    swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
                }
            }
            for(int i = 0; i < n / 2; i++){ 
                for(int j = 0; j < n; ++j){ 
                    swap(matrix[i][j], matrix[n - 1 - i][j]);
                }
            }
        }
};

//15.Plus One
class Solution {
    public:
        vector<int> plusOne(vector<int> & digit) {
            add(digit, 1);
            return digit;
        }
    private:
        void add(vector<int> & digit, int digit) {
            int c = digit;
            for(auto it = digit.rbigin(); it != digit.rend(); it++)
            {
                *it += c;
                c = *it / 10;
                *it = *it % 10;
            }
            if(c > 0) digit.insert(digit.begin(), 1);
        }
};

//16.Climbing Stairs
class Solution {
    int climbStairs(int n) {
        int prev = 0;
        int cur = 1;
        for(int i = 0; i <= n; i++) 
        {
            int tmp = cur;
            cur = prev + cur;
            prev = tmp;
        }
        return cur;
    }
};

//17.Single Number
//<1> Remember using XOR to get the result;

class Solution {
    public:
        int sigleNumber(int A[], int n) {
            int index = 0;
            for(size_t i = 0; i < n; i++)
                x ^= A[i];
            return x;
        }
};

//18.Single Number II
//
class Solution {
    public:
        int singleNumberII(int A[], int n) {
            int one = 0, two = 0, three = 0;
            for(int i = 0; i < n; i++) {
                two |= (one & A[i]);
                one ^= A[i];
                one &= three;
                two &= three;
            }
            return one;
        }
}；

//19.Reverse LinkedList
class Solution {
    ListNode * reverseLinkedList(ListNode * head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next;

        while(curr != NULL) {
            next = head -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

//20. Reverse Linked List II

class Solution {
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;

        ListNode *prev = dummy;
        for(int i = 0; i < m - 1; i++) {
            prev = prev -> next;
        }

        ListNode* const head2 = prev;

        prev = head2 -> next;
        ListNode * cur = prev -> next;
        
        for(int i = m; i < n; i++) {
                prev -> next = cur -> next;
                cur -> next = head2 -> next;
                head2 -> next = cur;
                cur = prev -> next;
        }

        return dummy.next;
    }
}

//21.Partition List
class Solution {
    ListNode * partition( ListNode *head, int x) {
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);

        auto left_cur = & left_dummy;
        auto right_cur = & right_dummy;

        for(ListNode * cur = head; cur; cur -> next) {
            if(cur -> val < x) {
                left_cur -> next = cur;
                left_cur = cur;
            } else {
                right_cur -> next = cur;
                right_cur = cur;
            }
        }

        left_cur -> next = right_dummy.next;
        right_cur -> next = NULL;
        return left_dummy.next;
    }
};

//22.Remove Duplicate from sorted List
//<1>  recursive call remove duplicate node
//<2> 
class Solution {
    public:
        ListNode * deleteDuplicate(ListNode * head) {
            if(head == NULL)
                return head;
            ListNode dummy(head -> val + 1);

            recur(&dummy, head);
            return dummy.next;
        }
    private:
        static void recur(ListNode * prev, ListNode * cur) {
            if(cur == NULL) return;
            if(prev -> val == cur -> val) { 
                prev -> next = cur -> next;
                delete cur;
                recur(prev, prev -> next);
            } else {
                recur(prev -> next, cur -> next);
            }
        }
};

//23. Remove Duplicate From Sorted List II
class Solution {
ListNode *deleteDuplicate(ListNode * head) {
    if(head != NULL || head -> next != NULL) \
        return head;

    ListNode *p = head -> next;
    if(head -> val == p -> val) {
        while(p && head -> val == p -> val) {
            ListNode * tmp = p;
            p = p -> next;
            delete tmp;
        }
        delete head;
        return deleteDuplicates(p)
    } else {
        head -> next = deleteDuplicates(head -> next);
        return head;
    }
};

//24.Rotate List
//
class Solution {
    public:
        ListNode * rotateRight(ListNode * head, int k) {
            if (head == NULL || k == 0) return head;

            int len = 1;
            ListNode * p = head;

            while(p -> next) {
                len++;
                p = p -> next;
            }

            k = len - k % len;

            p -> next = head;

            for(int step = 0; step < k; step++) {
                p = p -> next;
            }

            head = p -> next;
            p -> next = NULL;
            return head;
        }
}

//25.Remove Nth From End of List
//
class Solution {
    public:
        ListNode * removeFromeNthToEnd ( ListNode * head, int n) {
            ListNode dummy(-1);
            ListNode *p = & dummy, *q = & dummy;

            for(int i = 0; i < n; i++) {
                p = p -> next;
            }

            while(p -> next) {
                p = p -> next;
                q = q -> next;
            }

            ListNode * tmp = p -> next;
            p -> next = p -> next -> next;
            delete tmp;
            return dummy.next;
        }
};

//26.Swap Nodes in Pairs
// Need ask...
class Solution {
    public:
        ListNode * swapPairs(ListNode * head) {
            if(head == NULL || head -> next == NULL) 
                return head;

            ListNode dummy(-1);
            dummy.next = head;
            ListNode *n1 = & dummy, *n2 = & head;

            while(n2 != NULL && n1 != NULL) {
                ListNode * temp = n2 -> next -> next;
                n2 -> next -> next = n1 -> next;
                n1 -> next = n2 -> next;
                n2 -> next = temp;
                n1 = n2;
                n2 = n1 -> next;// how to understand this part?
            }
            return dummy.next;
        }
}

//27. Reverse in k - Group 
class Solution {
    public:
        ListNode * reverseKGroup(ListNode * head, int k) {
            if(head == NULL || head -> next == NULL || k < 2) 
                return head;

            ListNode * next_group = head;
            for(int i = 0; i < k; i++) {
                if(next_group) 
                    next_group = next_group -> next;
                else 
                    return head;
            }

            ListNode * new_next_group = reverseKGroup(next_group, k);

            ListNode * prev = NULL, * cur = head;
            while(cur != next_group) {
                ListNode * next = cur -> next;
            }
        }
}

//28. Linked List Cycle 
class Solution {
    public: 
        bool hasCycle(ListNode * head) {
            ListNode *slow, *fast;
            whlie(fast && fast -> next) {
                slow = slow -> next;
                fast = fast -> next -> next;
                if(slwo == fast) return true;
            }
            return false;
        }
}

//29. Linked List Cycle II
class Solution {
    ListNode * detectCycle(ListNode * head) {
        ListNode * slow = head, *fast = head;
        while(fast && fast -> next) {
            slwo = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow) {
                ListNode * head2 = head;
                whlie(slow2 != slow) {
                    slow2 = slow2 -> next;
                    slow = slow -> next;
                }
                return slow2;
            }
        }
        return NULL;
}

//30. Copy List with Random Pointer
//still need ask
class Solution {
    public:
        RandomListNode * copyRandomList (RandomListNode * head) {
            for (RandomeListNode * cur = head; cur != NULL) {
                RandomeListNode * node = new RandomListNode(cur -> lable);
                node -> next = cur -> next;
                cur -> next = node;
                cur = node -> next;
            }

            for(RandomeListNode * cur = head; cur != NULL; ) { 
                if(cur -> random != NULL) 
                    cur -> next -> random = cur -> random -> next;
                cur = cur -> next -> next;
            }

            RandomListNode dummy(-1);
            for(RandomListNode * cur = head, *new_cur = & dummy; cur != NULL;) {
                new_cur -> next = cur -> next;
                new_cur = new_cur -> next;
                cur -> next = cur -> next -> next;
                cur = cur -> next;
            }
            return dummy.next;
        }
};

//31.Reorder List
// l1 -> l2 -> l3 -> l4 -> ...-> ln
// l1 -> ln -> l2 -> ln-1....

class Solution {
    LinkNode *reoderList(ListNode * head) {
        if (head == NULL || head -> next == NULL)
            return NULL;
        ListNode *slow = head, *fast = head, *prev = NULL;
        while (fast && fast -> next) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        prev -> next = NULL; //Cut the list in middle;

        slow = reverse(slow);

        ListNode *curr = head;
        
        while (curr -> next) {
            ListNode *tmp = curr -> next;
            curr -> next = slow;
            slow = slow -> next;
            curr -> next -> next = tmp;
            curr = tmp;
        }

        ListNode *reverse(ListNode * head) {
            if (head == NULL || head -> next == NULL)
                return head;

            ListNode * prev = NULL;
            ListNode * curr = head;
            ListNode * next;

            while (curr != NULL) {
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }
            
            return prev;
        }
    }
};

//32. LRU cache

//33. Valid Palidrome
class Solution {
    public:
        bool isPalindrome(string s) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            auto left = s.begin(), right = prev(s.end());
            while (left < right) {
                if (!::isalnum(*left)) 
                    left++;
                else if (!isalnum(*right)) 
                    right--;
                else if (*left != *right) 
                    return false;
                else {
                    left++;
                    right--;
                }
            }
            return true;
        }
}

//34. Implement strStr()

class Solution {
    public:
        char* strStr(const char * haystack, const char* needle) {
            if (!needle) return (char*) haystack;

            const char *p1;
            const char *p2;
            const char *p1_advance = haystack;

            for (p2 = & needle[0]; *p2; p2++) {
                p1_advance++;
            }

            for (p1 = haystack; *p1_advance; p1_advance++) {
                char* p1_old = (char*) p1;
                p2 = needle;
                while (*p1 && *p2 && *p1 == *p2) {
                    p1++;
                    p2++;
                }

                if (!*p2) return p1_old;
                p1 = p1_old + 1;
            }
        }
}

//35. String to integer
class Solution {
    public:
        int atoi (const char *str) {
            int num = 0;
            int sign = 1;
            const int n = strlen(str);
            int i = 0;

            while (str[i] == ' ' && i < n) 
                i++;

            if (str[i] == ' ' && i < n) i++;
            if (str[i] == '-') {
                sign = -1;
                i++;
            }

            for (; i < n; i++) {
                if (str[i] < '0' || str[i] > 9) 
                    break;
                if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
                {
                    return sign == -1 ? INT_MIN : INT_MAX;
                }

                num = num * 10 + str[i] - '0';
            }
            return num * sign;
        }
}

//36. Add Binary 
class Solution {
    public:
        string addBinary (string a, string b) {
            string result;
            const size_t n = a.size() > b.size() ? a.size() : b.size();
            reverse (a.begin(), a.end());
            reverse (b.begin(), b.end());
            int carry = 0;

            for (size_t i = 0; i < n; i++) {
                const int ai = i < a.size() ? a[i] - '0' : 0;
                const int bi = i < b.size() ? b[i] - '0' : 0;
                const int val = (ai + bi + carry) % 2;
                carry = (ai + bi + carry) / 2;
                result.insert(result.begin(), val + '0');
            }

            if (carry == 1) {
                result.inset(result.begin(), '1');
            }
            return result;
        }
}

//37. Longest Palidrome Substring 

class Solution {
    public:
        string longestPalindrome (string s) {
            int startIndex = 0;
            int len = 0;
            int sI, eI;

            for (int i = 0; i < s.size() -1; i++) {
                if (s[i] == s[i + 1]) {
                    sI = i;
                    eI = i + 1;
                    Search (s, sI, eI, len, startIndex)
                }
                sI = i;
                eI = i;
                Search (s, sI, eI, len, startIndex);
            }
            if (len == 0) 
                len = s.size();
            return s.substr (startIndex, len);
        }

        void Search (string &s, int sI, int eI, int & len, int & startIndex) {
            int step = 1;
            while ((sI - step) >= 0 && (eI + step) < s.size()) {
                if (s[sI - step] != s[eI + step])
                {
                    break;
                }
                step++;
            }

            int wid = eI - sI + 2 * step -1;

            if(wid > len) {
                len = wid;
                startIndex = sI - step + 1;
            }
        }
}

//38. Regular Expression Matching
class Solution {
    public:
}

//39. Wildcard Matching
class Solution {
    public:
        bool isMatch(const char *s , const char *p) {
        }
}

//40.Longest Common Prefix
class Solution {
    public:
        string longestCommonPrefix (vector<string> & strs) {
            if (strs.empty()) return "";

            for (int idx = 0; idx < strs[0].size(); idx++) {
                for (int i = 1; i < strs.size(); i++) {
                    if (strs[i][idx] != strs[0][idx])
                         return strs[0].substr(0, idx);
                }
            }
            return strs[0];
        }
}

//41. Valid Number 
class Solution {
    public:
        bool isNumber (const char *s) {
        }
}

//42. Integer to Roman
class Solution {
    public:
        string intToRoman (int num) {
            const int radix[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
            string roman;

            for (size_t i = 0; num > 0; i++) {
                int count = num / radix[i];
                num %= radix[i];
                for (; count > 0; count--) 
                    roman += symbol[i];
            }
            return roman;
        }
};

//43. Roman to Integer

class Solution {
    public:
        inline int map (const char c) {
            swtich(c) {
                case 'I' : return 1;
                case 'V' : return 5;
                case 'X' : return 10;
                case 'L' : return 50;
                case 'C' : return 100;
                case 'D' : return 500;
                case 'M' : return 1000;
                default : return 0;
            }
        }

        int romanToInt (string s) {
            int result = 0;
            for (size_t i = 0; i < s.size(); i++) {
                if(i > 0 && map (s[i] > map (s[i - 1]))) {
                    return += (map(s[i]) - 2 * map(s[i - 1]));
                } else {
                    result += map (s[i]);
                }
                return result;
            }
        }
}

//44. Count and Say
class Solution {
    public:
        string countAndSay (int n) {
            if (n < 0) return NULL;
            string res = "1";

            while ( n-- > 1) {
                string tmp;
                int count = 1;
                for (int i = 1; i < res.size(); i++) 
                {
                    if (res[i] ==  res[i - 1]) {
                        count++;
                    } else {
                        char tmp1 = '0' + count;
                        tmp = tmp + tmp1;
                        count = 1;
                    }
                }
                char tmp1 = '0' + count;
                tmp = tmp + tmp1;
                tmp = tmp + res[res.size() - 1];
                res = tmp;
            }
            return res;
        }
};

//45.Angrams 
class Solution {
    public:
        vector<string> anagrams (vector<string> & strs) {
            unordered_map <string, vector<string>> group;
            for (const auto & s : strs) {
                string key = s;
                sort(key.begin(), key.end());
                group[key].push_back(s);
            }

            vector<string> result;
            for (auto it = group.cbegin(); it != group.cend(); it++) {
                if (it -> second.size() > 1)
                    result.insert(result.end(), it -> second.begin(), it -> second.end());
            }
            return result;
        }
}


//46.Simplify Path
// Question
class Solution {
    public:
        string simplifyPath (string const & path) {
            vector<string> dirs;

            for (auto i = path.begin(); i != path.end()) {
                i++;

                auto j = find(i, path.end(), '/');
                auto dir = string(i, j);

                if (!dir.empty() && dir != ".") {
                    if (dir == "..") {
                        if (!dirs.empty()) 
                            dirs.pop_back(dir);
                    } else
                        dirs.push_back(dir);
                }

                stringstream out;
                if (dirs.empty()) {
                    out << "/";
                } else {
                    for (auto dir : dirs) 
                        out << '/' << dir;
                }
                return out.str();
            }
        }
};

//47. Length of Last Word
class Solution {
    public:
        int lengthOfLastWord (const char *s) {
            int len = 0;
            while (*s) {
                if (*s++ != ' ')
                    len++;
                else if (*s && *s != ' ')
                    len = 0;
            }
            return len;
        }
};

//48.Binary Treee Preorder Traversal
class Solution {
    public:
        vector<int> preorderTraversal (TreeNode * root) {
            vector<int> result;
            const TreeNode *p;
            stack<const TreeNode *> s;
            
            p = root;
            if (p != NULL) s.push(p);

            while (!s.empty()) {
                p = s.top();
                s.pop();
                result.push_back(p -> val);

                if (p -> right != NULL) 
                    s.push(p -> right);
                if (p -> left != NULL) 
                    s.push(p -> left);
            }
            return result;
        }
}

//49. Binary Tree Inorder Traversal
class Solution {
    public:
        vector<int> inorderTraversal (TreeNode * root) {
            vector<int> result;
            const TreeNode * p = root;
            stack<const TreeNode *> s;

            while (!s.empty() || p != NULL) {
                if (p != NULL) {
                    s.push(p);
                    p = -> left;
                } else {
                    p = s.top();
                    s.pop();
                    result.push_back (p -> val);
                    p = p -> right;
                }
            }
            return result;
        }
};

//50. Binary Tree Postorder Traversal
class Solution {
    public:
        vector<int> postoderTraversal (TreeNode *root) {
            vector<int> result;
            TreeNode *p, *q;
            stack <const TreeNode *> s;

            p = root;

            do { 
                while (p != NULL) {
                    s.push(p);
                    p = p -> left;
                }
                q = NULL;
                while (!s.empty()) {
                    p = s.top();
                    s.pop();
                    if (p -> right == q) {
                        result.push_back(p -> val);
                        q = p;
                    } else {
                        s.push(p);
                        p = p -> right;
                        break;
                    }
                } 
            } while (!s.empty());
            return result;
        }
}

//51. Binary Tree Level Oder Traversal
class Solution {
    public:
        vector<vector<int> > levelOder (TreeNode * root) {
            vector <vector<int>> result;
            traverse (root, 1, result);
            return result;
        }

        void traverse (TreeNode * root, size_t level, vector<vector< int>> & result) {
            if (!root) return;

            if (level > result.size())
                result.push_back(vector<int>());

            result[level - 1].push_back(root -> val);
            traverse(root -> left, level + 1, result);
            traverse(root -> right, level + 1, result);
        }
};

//52. Binary Tree Level Oder Traversal II 

class Solution {
    public:
        vector<vector<int> > levelOderBottom (TreeNode * root) {
            vector<vector<int>> result;
            traverse(root, 1, result);
            std::reverse(result.bigin(), result.end());
        }

        void traverse (TreeNode *root, size_t level, vector<vector<int>> & result) {
            if (!root) return;

            if (level > result.size())
                result.push_back(vector<int>());

            result[leve - 1].push_back (root -> val);
            traverse (root -> left, level + 1; resutl);
            traverse (root -> right, level + 1; result);
        }
};

//53. Binary Tree Zigzag Level Oder Traversal

class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder (TreeNode * root) {
            vector<vector<int>> result;
            traverse (root, 1, result, true);
            return result;
        }

        void traverse (TreeNode * root, size_t level, vector<vector<int>> & result, 
                bool left_right) {
            if (!root) return;

            if (level > result.size()) 
                result.push_back(vector<int>());

            if (left_to_right)
                result[level - 1].push_back(root -> val);
            else 
                result[level - 1].inster(result[level - 1].begin(), root -> val);

            traverse (root -> left, level + 1, result, !left_to_right);
            traverse (root -> right, level + 1, result, !left_to_right);
        }
};

//54. Recover Binary Search Tree
//Ask
class Solution {
    public:
        void recoverTree(TreeNode * root) {
            pair<TreeNode *, TreeNode *> broken;
            TreeNode * prev = NULL;
            TreeNode * cur = root;

            while (cur != NULL) {
                if (cur -> left == NULL) {
                    detect(broken, prev, cur);
                    prev = cur;
                    cur = cur -> right;
                } else {
                    auto node = cur -> left;

                    while (node -> right != NULL && node -> right != cur) 
                        node = node -> right;

                    if (node -> right == NULL) {
                        node -> right = cur;
                        cur = cur -> left;
                    } else {
                        detect (broken, prev, cur);
                        node -> right = NULL;
                        prev = cur;
                        cur = cur -> right;
                    }
                }
            }
            swap(broken.first -> val, broken.second -> val);
        }

        void detect (pair <TreeNode *, TreeNode *> & broken, TreeNode * prev, TreeNode * current) {
            if (prev != NULL && prev -> val > current -> val) {
                if (broken.first == NULL) {
                    broken.fist = prev;
                } 
                broken.second = current;
            }
        }
};

//55.Same Tree
class Solution {
    public:
        bool isSameTree (TreeNode * p, TreeNode * q) {
            if (!p && !q) return true;
            if (!p || !q) return false;
            return p -> val == q -> val
                && isSameTree(p -> left, q -> left)
                && isSameTree(p -> right, q -> right);
        }
};

//56. Symeetric Tree
class Solution {
    public:
        bool isSymmetric (TreeNode * root) {
            return root ? isSymmetric(root -> left, root -> right) : true;
        }
        bool isSymmetric (TreeNode * left, TreeNode * right) {
            if (!left && !right) return true;
            if (!left || !right) return false;
            return left -> val == right -> val
                && isSymmetric(left -> left, right -> right) 
                && isSymmetric(left -> right, right -> left);
        }
};

//57. Balanced Binary Tree
class Solution {
    bool isBalanced (TreeNode * root) {
        return balanceHeight (root) >= 0;
    }

    int balanceHeight(TreeNode * root) {
        if (root == NULL) return 0;

        int left = balanceHeight (root -> left);
        int right = balanceHeight (root -> right);

        if (left < 0 || right < 0 || abs(left - right) > 1) return -1;

        return max(left, right) + 1;
    }
};

//58. Flatten Binary Tree to Linked List
// ASK
class Solution {
    public:
        void flatten (TreeNode *root) {
            if (root == NULL) return;

            flatten(root -> left);
            flatten(root -> right);

            if (NULL == root -> left) return;

            TreeNode * p = root -> left;
            while (p -> right) p = p -> right;
            p -> right = root -> right;
            root -> right = root -> left;
            root ->left = NULL;
        }
};

class Solution {
    public:
        void flatten (TreeNode * root) {
            flatten(root, NULL):
        }
    private:
        TreeNode *flatten(TreeNode *root, TreeNode * tail) {
            if (root == NULL) return tail;

            root -> right = flatten(root -> left, flatten(root -> right, tail));
            root -> left = NULL;
            return root;
        }
};


//59.Populating Next Right Pointers in Each Node II
class Solution {
    public:
        void connect (TreeLinkNode *root) {
            if (root == NULL) return;

            TreeLinkNode dummy(-1);
            for (TreeLinkNode *curr = root, *prev = &dummy; 
                    curr; curr = curr -> next) {
                if (curr -> left != NULL) {
                    prev -> next = curr -> nect;
                    prev = prev -> next;
                }
                if (curr -> right != NULL) {
                    prev -> next = curr -> right;
                    prev = prev -> next;
                }
            }
            connect(dummy.next);
        }
};

//60. Construct Binary Tree from Preoder and Inorder Traversal
//Prectice More
class Solution {
    public:
        TreeNode * buildTree(vector<int> & preorder, vector<int> & inorder) {
           return buildTree(preorder, inorder, 0, preorder.size() -1, 0, inorder.size() - 1);
        }

        TreeNode * (vector<int> &preorder, vector<in> &inorder, int preleft, int preright, int inleft, int inright) {
            if (preleft > preright || inleft > inright) {
                return NULL;
            }

            int leftsize = 0;

            for (int i = inleft; i <= inright; i++) {
                if (preorder[preleft] = inorder[i]) {
                    break;
                }
                leftsize++;
            }

            TreeNode *node = new TreeNode(preorder[preleft]);

            node -> left = buildTree(preorder, inorder, preleft + 1, preleft + leftsize,
                    inleft, inleft + leftsize - 1);
            node -> right = buildTree(preorder, inorder, preleft + leftsize + 1, preright, 
                    inleft + leftsize + 1, inright);
            return node;
        }
}

//61. Construct Binary Tree From Inorder and Postorder Traversal
class Solution {
    public:
        TreeNode * buildTree (vector<int> & inorder, vector<int> & postorder) {
            int inStart = 0;
            int inEnd = inorder.size() - 1;
            int postStart = 0;
            int postEnd = postorder.size() - 1;

            return buildTree(inorder, inStart, inEnd, postorder, postStart, postEnd);
        }

        TreeNode * buildTree (vector<int> & inorder, int inStart, int inEnd, vector<int> & postorder, int postStart, int postEnd) {
            if (inStart > inEnd || postStart > postEnd) {
                return NULL;
            }

            int rootValue[postEnd];

            TreeNode * root = new TreeNode(rootValue);

            int k = 0; 

            for (int i = 0; i < inorder.size(); i++) {
                if (inorder[i] == rootValue) {
                    k = i;
                    break;
                }
            }

            root -> left = buildTree (inorder, inStart, k - 1, postorder, postStart, 
                    postStart + k - (inStart + 1));

            root -> right = buildTree (inorder, k + 1, inEnd, postorder, postStart + k - inStart, postEnd - 1);
            return root;
        }
}

//61. Unique Binary Search Tree
//数学归纳法
class Solution {
    public:
        int numTree(int n) {
            vector<int> f(n + 1, 0);

            f[0] = 1;
            f[1] = 1;

            for (int i = 2; i <= n; i++) {
                for (int k = 1; k <= i; k++)
                    f[i] += f[k - 1] * f[i - k];
            }

            return f[n];
        }
};

//62.Unique Binary Search Tree II
// Ask
class Solution {
    public:
        vector<TreeNode *> generateTree(int n) {
            if (n == 0) return generate(1, 0);
            return generate(1, n);
        }
    private:
        vector<TreeNode *> generate (int start, int end) {
            vector<TreeNode *> subTree;
            if (start > end) {
                subTree.push_back(NULL);
                return subTree;
            }

            for (int k = start, k <= end; k++) {
                vector<TreeNode *> leftSubs = generate(start, k - 1);
                vector<TreeNode *> rightSubs = generate(k + 1, end);
                for (auto i : leftSubs) {
                    for (auto i : rightSubs) {
                        TreeNode * node = new TreeNode(k);
                        node -> left = i;
                        node -> right = j;
                        subTree.push_back(node);
                    }
                }
            }
            return subTree;
        }
};

//63.Valid Binary Search Tree
class Solution {
    public:
        bool isValidBST (TreeNode * root) {
            return isValidBST (root, INT_MIN, INT_MAX);
        }

        bool isValidBST (TreeNode * root, int lowe, int upper) {
            if (root == NULL) return true;

            return root -> val > lower && root -> val < upper
                && isValidBST(root -> left, lower, root -> val)
                && isValidBST(root -> right, root -> val, upper);
        }
}

//64.Convert Sorte Array To Binary Search Tree

class Solution {
    public:
        TreeNode * sorttedArrayToBST (vector<int> & num) {
            if (num.length() == 0)
                return NULL;
            return sortedArrayToBST (num, 0, num.length() - 1);
        }

        TreeNode * sortedArrayToBST (vector<int> & num, int start, int end) {
            if (start > end) 
                return NULL;

            int mid = (start + end) / 2;

            TreeNode * root = new TreeNode (num[mid]);

            root -> left = sortedArrayToBST(num, start, mid - 1);
            root -> right = sortedArrayToBST(num, mid + 1, end);

            return root;
        }
}

//65. Convert Sorted list to Binary Search Tree
// Time Out???
class Solution {
    TreeNode * sortedListToBST (ListNode * head) {
        return sortedListToBST (head, listLength(head));
    }

    int listLength(ListNode * node) {
        int n = 0;
        while (head) {
            n++;
            node = node -> next;
        }

        return n;
    }

    TreeNode * sortedListToBST (ListNode * head, int len) {
        if (len == 0) return NULL;

        if (len == 1) return new TreeNode(head -> val);

        TreeNode * root = new TreeNode ( nth_node (head, len / 2 + 1) -> val);

        root -> left = sortedListToBST(head, len / 2);

        root -> right = sortedListToBST (nth_node (head , len / 2 + 2), (len - 1) / 2);

        return root;
    }

    ListNode * nth_node (ListNode * node, int n) {
        while (n--) {
            node = node -> next;
        }
        return node;
    }
}

//66.Minimum Depth of Binary 
class Solution {
    public:
        int minDepth (const TreeNode * root) {
            return minDepth(root, false);
        }
    private:
        static int minDepth(const TreeNOde * root, bool hasbrother) {
            if (!root) return hasbrother ? INT_MAX : 0;

            return 1 + min(minDepth(root -> left, root -> right != NULL), 
                    minDepth(root -> right, root -> left != NULL));
        }
};

//67.Maximu Depth of Binary Tree
class Solution {
    int maxDepth (TreeNode * root) {
        if (root == NULL) return 0;

        return max (maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
}

//68.Path Sum
class Solution {
    public:
        bool hasPathSum (TreeNode * root, int sum) {
            return hasPathSum(root, 0, sum);
        }

        bool hasPathSum (TreeNode * root, int sum, int target) {
            if (root == NULL) return false;

            if (root -> left == NULL && root -> right == NULL) {
                if (sum == target) 
                    return true;
                else 
                    return false;
            }

            return hasPathSum(root -> left, sum, target) 
                || hasPathSum(root -> right, sum, target);
        }
}

//69. Path Sum II
class Solution {
    public:
        vector<vector<int>> pathSum (TreeNode * root, int sum) {
            vector<vector<int>> collect;
            vector<int> solution;

            if(root != NULL) 
                GetPath(root, sum, 0,  solution, collect);
            return collect;
        }

        void GetPath (TreeNode * root, int sum, int cal, vector<int> & solution, 
                vector<vector<int>> & collect) {
            solution.push_back(root -> val);
            cal += node -> val;

            if (cal == sum && node -> left == NULL && node -> right == NULL)
            {
                collect.push_back(solution);
            }
            else {
                if (node -> left != NULL) {
                    GetPath(node -> left, sum, cal, solution, collect);
                }

                if (node -> right != NULL) {
                    GetPath (node -> right, sum, cal, solution, collect);
                }
            }

            solution.pop_back();

            cal -= node -> val;

            return;
        }
}


//70. Binary Tree Maximum Path Sum
// ASK 
class Solution {
    public:
        int maxPathSum (TreeNode *root) {
            max_sum = INT_MAX;
            dfs(root);
            return max_sum;
        }
    private:
        int max_sum;
        int dfs (const TreeNode * root) {
            if (root == NULL) return 0;
            int l = dfs(root -> left);
            int r = dfs(root -> right);
            int sum = root -> val;
            if (l > 0) sum += l;
            if (r > 0) sum += r;

            max_sum = max(max_sum, sum);
            return max(r, l) > 0 ? max(r, l) + root -> val : root -> val;
        }
};

//71. Populating next Right Pointer in Each Node 
class Solution {
    public:
        void connect(TreeLinkNode * root) {
            if (root == NULL) {
                return;
            }

            if (root -> left != NULL) {
                root -> left -> next = root -> right;
            }

            if (root -> right != NULL) {
                root -> right -> next = root -> next ? root -> next -> left : NULL;
            }

            connect(root -> left);
            connect(root -> right);
        }
}

//72. Sum Root to Leaf Numbers
class Solution {
    public:
        int sumNumbers(TreeNode * root) {
            return dfs(root, 0);
        }

    private:
        int dfs(TreeNode * root, int sum) {
            if (root == NULL) return 0;
            if (root -> left == NULL && root -> right == NULL) 
                return sum * 10 + root -> val;

            return dfs(root -> left, sum * 10 + root -> val) +
                dfs(root -> right, sum * 10 + root -> val);
        }
};

//73. Merge Two Sorted Array
class Solution {
    public:
        void merge (int A[], int m, int B[], int n) {
            int k = m + n - 1;
            int i = m - 1, j = n - 1;

            for (; i >= 0 && j >= 0; k--) {
                if (A[i] >= B[i]) {
                    A[k] = A[i];
                    i--;
                } else {
                    A[k] = B[j];
                    j--;
                }
            }

            while (j >= 0) {
                A[k] = B[j];
                k--;
                j--;
            }
        }
};

//74. Merge Two Sorted List
class Solution {
    public:
        ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
            ListNode* p1 = l1;
            ListNode* p2 = l2;

            ListNode dummy(-1);
            ListNode * p = dummy;

            while (p1 != NULL && p2 != NULL) {
                if (p1 -> val <= p2 -> val) {
                    p -> next = p1;
                    p1 = p1 -> next;
                } else {
                    p -> next = p2;
                    p2 = p2 -> next;
                }

                p = p -> next;
            }

            if (p1 != NULL)
                p -> next = p1;
            if (p2 != NULL) 
                p -> next = p2;

            return dummy.next;
        }
}

//75. Merge K Sorted Lists
class Solution {
    public:
        ListNode * mergeKLists(vector<ListNode *> & lists) {
            if (lists.size() == 0) return NULL;
            ListNode * p = lists[0];
            for (int i = 1; i < lists.size(); i++) {
                p = merge2Lists(p, lists[i]);
            }
            return p;
        }

        ListNode * merge2Lists (ListNode * head1, ListNode * head2) {
            ListNode * head = new ListNode(INT_MIN);
            ListNode * p = head;
            while (head1 != NULL && head2 != NULL) {
                if (head1 -> val < head2 -> val) {
                    p -> next = head1;
                    head1 = head1 -> next;
                } else {
                    p -> next = head2;
                    head2 = head2 -> next;
                }
                head = head -> next;
            }
            if (head1 != NULL) {
                p -> next = head1;
            }

            if (head2 != NULL) {
                p -> next = head2;
            }

            p = head;
            head = head -> next;
            delete p;
            return head;
        }
}


//76. Insertion Sort List
class Solution {
    ListNode * insertionSortList (ListNode * head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode * dummy = new ListNode (0);
        ListNode * pre = dummy;
        ListNode * cur = head;

        while (cur != NULL) {
            ListNode * next = cur -> next;
            pre = dummy;
            while (pre -> next != NULL && pre -> next -> val < cur -> val) {
                pre = pre -> next;
            }

            cur -> next = pre -> next;
            pre -> next = cur;
            cur = next;
        }

        return dummy -> next;
    }
}

//77. Sort List
class Solution {
    ListNode * sortList (ListNode * head) {
        if (head == NULL || head -> next == NULL) return head;

        ListNode * fast = head, *slow = head;

        while (fast -> next != NULL && fast -> next -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        fast = slow;
        slow = slow -> next;
        fast -> next = NULL;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return merge2Lists(l1, l2);
    }

    ListNode * merge2Lists(ListNode * l1, ListNode * l2) {
        ListNode * head = new ListNode(INT_MIN);
        ListNode * p = head;

        while (l1 != NULL && l2 != NULL) {
            if (l1 -> val < l2 -> val) {
                p -> next = l1;
                l1 = l1 -> next;
            } else {
                p -> next = l2;
                l2 = l2 -> next;
            }
            p -> next;
        }

        if (l1 != NULL) {
            p -> next = l1;
        }

        if (l2 != NULL) {
            p -> next = l2;
        }

        p = head;
        head = head -> next;
        delete p;
        return head;
    }
}

//78.First Missing Positive


//79.Sort Colors


//80. Search For Range
//Ask
class Solution {
    public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);

        int start = 0, end = n - 1;

        while (start < end) {
            int mid = (start + end) / 2;
            if (A[mid] < target) {
                start = mid + 1;
                continue;
            }
            end = mid;
        }

        int low_bond = A[start] == target ? start : -1;
        if (lowe_bond == -1) {
            return result;
        }

        start = low_bound, end = n;
        while (start < end) {
            int mid = (start + end) / 2;
            if (A[mid] > target) {
                end = mid;
                continue;
            }
            start = mid + 1;
            int high_bound = start - 1;
            result.clear();
            result.push_back(low_bound);
            result.push_back(hight_bound);
            return result;
        }
    }
}


//81.Search Insert Position 
// Ask
class Solution {
    public:
        int searchInsert (int A[], int n, int target) {
            int l = 0, r = n - 1;
            while (l < = r) {
                int mid = (l + r) / 2;
                if (A[mid] == target) return mid;
                if (mid > 1 && A[mid] > target && A[mid - 1] < target) return mid;
                if (A[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        }
}


//82. Search a 2D Matrix
class Solution {
    bool searchMatrix(const vector<vector<int>> & matrix, int target) {
        if (matrix.empty()) 
            return false;

        const size_t m = matrix.size();
        const size_t n = matrix.front().size();

        int first = 0;
        int last = m * n;

        while (first < last) {
            int mid = first + (last - first) / 2;
            int value = matrix[mid / n][mid % n]; // why is %

            if (value == target) 
                return true;
            else 
                last = mid;
        }
        return false;
    }
};

//83.

//84.


//85.Palindrome Partition
class Solution {
    public:
        vector<vector<string>> partition (string s) {
            vector<vector<string>> result;
            vector<string> path;
            dfs (s, path, result, 0, 1);
            return result;
        }

        void dfs (string & s, vector<string> & path, vector<vector<string> & result,
                size_t prev, size_t start) {
            if (start == s.size()) {
                if (isPalindrome(s, prev, start - 1)) {
                    path.push_back (s.substr (prev, start - prev));
                    result.push_back(path);
                    path.pop_back();
                }
                return;
        }
        dfs (s, path, result, prev, start + 1);
        if (isPalindrome(s, prev, start -1)) {
            path.push_back(s.substr(prev, start - prev));
            dfs (s, path, result, start, start + 1);
            path.pop_back();
        }
        }

        bool isPalindrome (const string & s, int start, int end) {
            while (s[start] == s[end]) {
                start++;
                end++;
            }
            return start >= end;
        }
};

class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> result;
            vector<string> path;
            DFS (s, path, result, 0);
            return result;
        }

        void DFS (string & s, vector<string>  & path, vector<vector<string> & result, int start) {
            if (start == s.size()) {
                result.push_back(path);
                return;
            }

            for (int i = start, i < s.size(); i++) {
                if (isPalindrome(s, start, i)) {
                        path.push_back (s.substr (start, i - start + 1));
                        DFS (s, path, result, i + 1);
                        path.pop_back();
                }
            }
        }

        bool isPalindrome (const string & s, int start, int end) {
            while (s[start] == s[end]) {
                start++;
                end++;
            }
            return start >= end;
        }
}

//86. Unique Path
//Still need ask O() and space 
class Solution {
    public: 
        int uniquePath (int m, int n) {
            if (m < 1 || n  < 1) return 0;

            if (m == 1 && n == 1) return 1;

            return uniquePath (m - 1, n) + uniquePath(m, n - 1);
        }
}

class Solution {
    public:
        int uniquePath (int m, int n) {
            this -> f = vector<vector<int>> ( m + 1, vector<int> (n + 1, 0));

            return dfs (m, n);
        }
    private:
        vector<vector<int>> f;

        int dfs (int x, int y) {
            if (x < 1 || y < 1) return 0;

            if (x == 1 && y == 1) return 1;

            return getOrUpdate (x - 1, y) + getOrUpdate (x, y - 1);
        }

        int getOrUpdate (int x, int y) {
            if (f[x][y] > 0) return f[x][y];

            else return f[x][y] = dfs(x, y);
        }
};


//87. Unique Path II

class Solution {
    public:
        int uniquePathsWithObstacles (vector<vector<int>> & obstacleGrid) {
            const int m = obstacleGrid.size();
            const int n = obstacleGrid[0].size();

            this -> f = vector<vector<int>> (m + 1, vector<int> (n + 1, 0));
            return dfs(obstacleGrid, m, n);
        }

    private:
        vector<vector<int>> f;

        int dfs(const vector<vector<int>> & obstacleGrid, int x, int y) {
            if (x < 1 || y < 1) return 0;

            if (obstacleGrid[x - 1][y - 1]) return 0;

            if (x == 1 && y == 1) return 1;

            return getOrUpdate (obstacleGrid, x - 1, y) + getOrUpdate (obstacleGrid, x, y - 1);
        }

        int getOrUpdate (const vector<vector<int>> & obstacleGrid, int x, int y) {
            if (f[x][y] > 0) 
                return f[x][y];
            else 
                return f[x][y] = dfs (obstacleGrid, x, y);
        }
};


//88.N - Queens
class Solution {
    public:
        vector<vector<string>> solveNQueens (int n) {
            this -> columns = vector<int> (n, 0);
            this -> main_diag = vector<int> (2 * n, 0);
            this -> anti_diag = vector<int> (2 * n, 0);

            vector<vector<string>> result;
            vector<int> C (n, 0);
            dfs (C, result, 0);
            return result;
        }

    private:
        vector<int> columns;
        vector<int> main_diag;
        vector<int> anti_diag;

        void dfs (vector<int> & C, vector<vector<string>> & result, int row) {
            const int N = C.size();

            if (row == N) {  
                vector<string> solution;
                for (int i = 0; i < N; i++) {
                    string s(N, '.');
                    for (int j = 0; j < N; j++) {
                        if (j == C[i]) s[j] = 'Q';
                    }
                    solution.push_back(s);
                }
                result.push_back (solution);
                return;
            }

            for (int j = 0; j < N; j++) {
                const bool ok = columns[j] == 0 && main_diag[row + j] == 0 
                    && anti_diag[row - j + N] == 0;

                if (!ok) continue;

                C[row] = j;
                columns[j] = main_diag[row + j] = anti_diag[row -j + N] = 1;
                dfs (C, result, row + 1);
                columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 0;
            }
        }
};

//89. N-Queens II
class Solution {
    public:
        int totalNQueens (int n) {
            this -> count = 0;
            this -> columns = vector<int> (n, 0);
            this -> main_diag = vector<int> (n * 2, 0);
            this -> anti_diag = vector<int> (2 * n, 0);

            vector<int>  C(n, 0);
            dfs (C, 0);
            return this -> count;
        }
    private:
        vector <int> columns;
        vector <int> main_diag;
        vector <int> anti_diag;

        void dfs (vector<int> & C, int row) {
            const int N = C.size();
            if (row == N) {
                this -> count++;
                return;
            }

            for (int j = 0; j < N; j++) {
                const bool ok = colume[j] == 0 &&
                    main_diag[row + j] == 0 &&
                    anti_diag[row - j + N] == 0;

                if (!ok) continue;
                
                C[row] = j;
                columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 1;

                dfs (C, row + 1);

                columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 0;
            }
        }
};

//90.Restore IP Addreesses

class Solution {
    public:
        vector<string> restoreIpAddresses (string s) {
            vector<string> result;
            string ip;
            dfs(s, 0, 0, ip, result);
            return result;
        }

        void dfs (string s, size_t start, size_t step, string ip, vector<string> & result) {
            if (start == s.size() && step == 4) {
                ip.resize(ip.size() - 1);
                result.push_back(ip);
                return;
            }

            if (s.size() - start > (4 -step) * 3)
                return;
            if (s.size() - start < (4 - step)) 
                return;

            int num = 0;
            for (size_t i = start; i < start + 3; i++) {
                num = num * 10 + (s[i] - '0');

                if (num <= 255) {
                    ip += s[i];
                    dfs (s, i + 1, step + 1, ip + '.', result);
                }
                if (num == 0) break;
            }
        }
};

//91. Combination Sum
class Solution {
    public:
        vector<vector<int>> combinationSum (vector<int> & nums, int target) {
            sort(nums.begin(), num.end());
            vector<vector<int>> result;
            vector<int> intermediate;
            dfs (nums, target, 0, intermediate, result);
            return result;
        }

    private:
        void dfs (vector<int> & nums, int gap, int start, vector<int> & intermediate, 
                vector<vector<int>> & result) {
            if (gap == 0) {
                result.push_back(intermediate);
                return;
            }
            for (size_t i = start; i < nums.size(); i++) {
                if (gap < nums[i]) return;

                intermediate.push_back(num[i]);
                dfs(nums, gap - nums[i], i, intermediate, result) ;
                intermediate.pop_back();
            }
        }
};

//92. Combination Sum II
class Solution {
    public:
        vector<vector<int>> combinationSum2(vecotr<int> & nums, int target) {
            sort(num.begin(), num.end());

            vector<vector<int>> result;
            vector<itn> intermediate;
            dfs(nums, target, 0, intermediate, result);
            return result;
        }
    private:
        static void dfs (vector<int> & nums, int gap, int start, vector<int> & intermediate, vector<vector<int>> & result) {
            if (gap == 0) {
                result.push_back(intermediate);
                return;
            }

            int previous = -1;
            for (size_t i = start, i < nums.size(); i++) {
                if (previous == num[i]) continue;

                if (gap < num[i]) return;

                intermediate.push_back(nums[i]);
                dfs(nums, gap - nums[i], i + 1, intermediate, result);
                intermediate.pop_back();
            }
        }
};

//93. Generate Parentheses
class Solution {
    public:
        vector<string> generateParenthesis (int n) {
            vector<string> result;
            if (n > 0) generate(n, "", 0, 0, result);
            return result;
        }

        void generate (int n, string s, int l, int r, vector<string> & result) {
            if (l == r) {
                result.push_back(s.append(n - r, ')'));
                return;
            }
            generate(n, s + "(", l, r + 1， result);
            if (l > r) generate(n, s + ")", r + 1, result);
        }
};

//94.Sudoku Solver
class Solution {
    public:
    bool solveSudoku (vector<vector<char>> & board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; k++) {
                        board[i][j] = '1' + k;
                        if (isValid(board, i, j) && solveSudoku(board))
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    private:
    bool isValid (const vector<vector<char>> &board, int x, int y) {
        int i, j;
        for (i = 0; i < 9; i++) 
            if (i != x && board[i][y] == board[x][y])
                return false;
        for (j = 0; j < 9; j++)
            if (j != y && board[x][j] == board[x][y])
                return false;
        for (i = 3 * (x / 3); i < 3 * (x /3 + 1); i++) 
            for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)
                if ((i != x || j != y) && board[i][j] == board[x][y])
                    return false;
        return true;
    }
};

//95. Word Search
class Solution {
    public:
        bool exist (vector<vector<char>> & board, string word) {
            const int m = board.size();
            const int n = board[0].size();
            vector<vector<bool>> visited (m, vector<bool> (n, false));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++)
                    if (dfs(board, word, 0, i, j, visited))
                        return true;
            }
            return false;
        }
    private:
        static bool dfs (const vector<vector<char> > & board, const string & word,
                int index, int x, int y, vector<vector<bool> > &visited) {
            if (index == word.size()) 
                return true;
            if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
                return false;

            if (visited[x][y]) 
                return false;

            if (board[x][y] != word[index]) 
                return false;
            
            visited[x][y] = true;

            bool ret = dfs (board, word, index + 1, x - 1, y, visited) ||
                     ret = dfs (board, word, index + 1, x + 1, y, visited) ||
                     ret = dfs (board, word, index + 1, x, y - 1, visited) ||
                     ret = dfs (board, word, index + 1, x, y + 1, visited);
            visited[x][y] = false;
            return ret;
        }
}

//96. Pow(x, n)
//97. Sqrt(x)
//98. Jump Game
//99. Jump Game II
//100. Best Time To Buy and Sell Stock
//101. Best Time To Buy and Sell Stock II
//102. Longest Substring Without Repeating Characters
//103. Container With Most Water

//104. Triangle
// ASK
class Solution {
    public:
       int minmumTotal (vector<vector<int>> & triangle) {
           int row = triangle.size();
           if (row == 0) return 0;
           vector<int> minV(triangle[row - 1].size());

           for (int i = row - 1; i >= 0; i--) {
               int col = triangle[i].size();
               for (int j = 0; j < col; j++) {
                   if (i == row - 1) // bottom of triangle
                   {
                       minV[j] = triangle[i][j];
                       continue;
                   }

                   minV[j] = min (minV[j], minV[j + 1]) + triangle[i][j];
               }
           }

           return minV[0];
}


//105. Maximum Subarray
//是说只要是array里面的元素就能够加么？？？
class Solution {
    public:
        int maxSubArray(int A[], int n) {
            int result = INT_MIN, f = 0;

            for (int i = 0; i < n; i++) {
                f = max(f + A[i], A[i]);
                result = max (result, f);
            }
            return result;
        }
};

//106. Palindrome Partitioning II
class Solution {
    public:
        int minCut (string s) {
            const int n = s.size();
            int f[n + 1];
            bool p[n][n];
            fill_n (& p[0][0], n * n, false);

            for (int i = 0; i <= n; i++) 
                f[i] = n - 1 - i;
            for (int i = n - 1, i >= 0; i--) {
                for (int j = i; j < n; j++) {
                    if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
                        p[i][j] = true;
                        f[i] = min(f[i], f[j + 1] + 1);
                    }
                }
            }
            return f[0];
        }
};

//107. Maximal Rectangle 

//108. Best Time to Buy and Sell Stock III

//107. InterLeaving String
//

//108. Scramble String
//

//109.Minimum Path Sum

//110.Edit Distance

//111. Decode Ways

//112.Distinct Subsequences
//

//113.Word Break

//114.Word Break II

//115.Clone Graph
class Solution {
    public:
        UndirectedGraphNode * cloneGraph (const UndirectedGraphNode * node) {
            if (node == NULL) return NULL;

            unordered_map <const UndirectedGraphNode *, UndirectedGraphNode *> copied;
            
            clone(node, copied);
            return copied[node];
        }
    private:
        static UndirectedGraphNode * clone (const UndirectedGraphNode *node, unordered_map UndirectedGraphNode *, UndirectedGraphNode *> & copied) {
            if (copied.find(node) != copied.end()) return copied[node];

            UndirectedGraphNode * new_node = new UndirectedGraphNode(node -> lable);

            copied[node] = new_node;
            for (auto nbr : node -> neighbors)
                new_node -> neighbors.push_back(clone(nbr, copied));
            return new_node;
        }
}

//116.Palindrome Number
class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) return false;
            int d = 1;
            while (x / d >= 10) d *= 10;

            while (x > 0) {
                int q = x / d;
                int r = x % 10;
                if (q != r) return false;
                x = x % d / 10;
                d /= 100;
            }
            return true;
        }
}

//117. Insert Interval




























