struct Point {
    double x, y;
};

double crossProduct(Point vector1, Point vector2) {
    return vector1.x * vector2.y - vector1.y * vector2.x;
}

bool isPointInsideQuadrilateral(Point A, Point B, Point C, Point D, Point P) {
    Point AP = {P.x - A.x, P.y - A.y};
    Point BP = {P.x - B.x, P.y - B.y};
    Point CP = {P.x - C.x, P.y - C.y};
    Point DP = {P.x - D.x, P.y - D.y};

    double ABP = crossProduct(AP, BP);
    double BCP = crossProduct(BP, CP);
    double CDP = crossProduct(CP, DP);
    double DAP = crossProduct(DP, AP);

    // Check if point P is on the same side of each edge of the quadrilateral
    bool isInside = (ABP >= 0 && BCP >= 0 && CDP >= 0 && DAP >= 0) ||
                    (ABP <= 0 && BCP <= 0 && CDP <= 0 && DAP <= 0);

    return isInside;
}
