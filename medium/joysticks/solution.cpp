int solution(int a1, int a2) {
    int time = 0, charger = 0;

    if (a2 < a1) {
        charger = 1;
    }

    if (a2 - 2 < 0 && a1 - 2 < 0) {
        return 0;
    }

    while (a1 > 0 && a2 > 0) {
        if (charger && a1 - 2 <= 0) {
            charger = 0;
        }

        if (charger == 0 && a2 - 2 <= 0) {
            charger = 1;
        }

        if (charger) {
            a1 -= 2;
            a2++;
        } else {
            a2 -= 2;
            a1++;
        }

        time++;
    }

    return time;
}
