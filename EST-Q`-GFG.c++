class Solution {
  public:

    long long orientation(int a[], int b[], int c[]) {
        long long val =
            (long long)(b[1] - a[1]) * (c[0] - b[0]) -
            (long long)(b[0] - a[0]) * (c[1] - b[1]);

        if (val == 0) return 0;
        return (val > 0) ? 1 : 2;
    }

    bool onSegment(int a[], int b[], int c[]) {
        return (b[0] <= max(a[0], c[0]) && b[0] >= min(a[0], c[0]) &&
                b[1] <= max(a[1], c[1]) && b[1] >= min(a[1], c[1]));
    }

    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {

        long long o1 = orientation(p1, q1, p2);
        long long o2 = orientation(p1, q1, q2);
        long long o3 = orientation(p2, q2, p1);
        long long o4 = orientation(p2, q2, q1);


        if (o1 != o2 && o3 != o4)
            return "true";

        if (o1 == 0 && onSegment(p1, p2, q1)) return "true";
        if (o2 == 0 && onSegment(p1, q2, q1)) return "true";
        if (o3 == 0 && onSegment(p2, p1, q2)) return "true";
        if (o4 == 0 && onSegment(p2, q1, q2)) return "true";

        return "false";
    }
};
