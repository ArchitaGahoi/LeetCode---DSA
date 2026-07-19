int compare(const void *a, const void *b) {
    char ab[25], ba[25];

    sprintf(ab, "%d%d", *(int *)a, *(int *)b);
    sprintf(ba, "%d%d", *(int *)b, *(int *)a);

    return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {

    qsort(nums, numsSize, sizeof(int), compare);

    if (nums[0] == 0) {
        char *ans = (char *)malloc(2);
        strcpy(ans, "0");
        return ans;
    }

    char *result = (char *)malloc(numsSize * 11 + 1);
    result[0] = '\0';

    for (int i = 0; i < numsSize; i++) {
        char temp[12];
        sprintf(temp, "%d", nums[i]);
        strcat(result, temp);
    }

    return result;
}