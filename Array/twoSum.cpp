#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int na = int(A.size()), nb = int(B.size());
        int n = na + nb;
        if (n % 2) {
            return solve(A, B, n / 2, 0, na - 1, 0, nb - 1);
        } else {
            return 1.0 *
                   (solve(A, B, n / 2 - 1, 0, na - 1, 0, nb - 1) +
                    solve(A, B, n / 2, 0, na - 1, 0, nb - 1)) / 2;
        }
    }

private:
    int solve(vector<int>& A, vector<int>& B, int k, int aStart, int aEnd,
              int bStart, int bEnd) {
        if (aEnd < aStart) return B[k - aStart];
        if (bEnd < bStart) return A[k - bStart];

        int aIndex = (aStart + aEnd) / 2;
        int bIndex = (bStart + bEnd) / 2;
        int aValue = A[aIndex], bValue = B[bIndex];

        if (aIndex + bIndex < k) {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
            } else {
                return solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
            }
        } else {
            if (aValue > bValue) {
                return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);
            } else {
                return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);
            }
        }
    }
};

int main() {
    int n1, n2;
    cout << "Enter number of elements in first sorted array: ";
    cin >> n1;
    vector<int> A(n1);
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < n1; i++) cin >> A[i];

    cout << "Enter number of elements in second sorted array: ";
    cin >> n2;
    vector<int> B(n2);
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n2; i++) cin >> B[i];

    Solution sol;
    double median = sol.findMedianSortedArrays(A, B);
    cout << "Median is: " << median << endl;

    return 0;
}



/*hello
Algorithm
Let's define a function that helps us find the k 
th
  smallest element from two inclusive ranges [a_start, a_end] and [b_start, b_end] from arrays A and B.

If the range (for example, a range of A) is empty, in other words a_start > a_end, it means all elements in A are passed, we just return the (k - a_start)-th element from the other array B. Vice versa if b_start > b_end.

Otherwise, get the middle indexes of the two ranges: a_index = (a_start + a_end) / 2, b_index = (b_start + b_end) / 2.

Get the middle values of the two ranges: a_value = A[a_index], b_value = B[b_index].

Cut one array in half, according to:

If a_index + b_index < k, cut one smaller half.
If a_value < b_value, cut the smaller half of A.
Otherwise, cut the smaller half of B.
Otherwise, cut one larger half.
If b_value < a_value, cut the larger half of B.
Otherwise, cut the larger half of A.
Repeat step 1 using the new starting and ending indexes of A and B.

Then we move on to find the median elements, and get the length of both arrays na = len(A) and nb = len(B).

If the total number of elements in A and B is odd, we just use the above function to find the middle element, that is k = (na + nb) / 2.
Otherwise, we use the function to find two middle elements: k = (na + nb) / 2 - 1 and k = (na + nb) / 2, and return their average.

*/