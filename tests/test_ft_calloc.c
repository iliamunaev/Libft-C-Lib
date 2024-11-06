#include "../imtest42/imtest42.h"
#include "tests.h"
#include <string.h>   // For comparison with the standard calloc

void	test_ft_calloc(void)
{
    void *ptr_ft;
    void *ptr_std;
    size_t nmemb, size;
    int cmp_result;

    // Test 1: Normal allocation
    nmemb = 10;
    size = sizeof(int);
    ptr_ft = ft_calloc(nmemb, size);
    ptr_std = calloc(nmemb, size);
    IM_ASSERT_PTR_NOT_NULL(ptr_ft);
    IM_ASSERT_PTR_NOT_NULL(ptr_std);
    cmp_result = memcmp(ptr_ft, ptr_std, nmemb * size);
    IM_ASSERT_INT_EQUAL(cmp_result, 0);
    free(ptr_ft);
    free(ptr_std);

    // Test 2: Zero elements
    nmemb = 0;
    size = sizeof(int);
    ptr_ft = ft_calloc(nmemb, size);
    //ptr_std = calloc(nmemb, size);
    IM_ASSERT_PTR_NULL(ptr_ft); // Should be NULL according to your definition
    // IM_ASSERT_PTR_NULL(ptr_std); // May return NULL or any mem address, see 'man calloc'
    free(ptr_ft);
    //free(ptr_std);

    // Test 3: Zero size
    nmemb = 10;
    size = 0;
    ptr_ft = ft_calloc(nmemb, size);
    //ptr_std = calloc(nmemb, size);
    IM_ASSERT_PTR_NULL(ptr_ft); // Should be NULL according to your definition
   // IM_ASSERT_PTR_NULL(ptr_std); // May return NULL or any mem address, see 'man calloc'
    free(ptr_ft);
    //free(ptr_std);

    // Test 4: Both zero
    nmemb = 0;
    size = 0;
    ptr_ft = ft_calloc(nmemb, size);
    //ptr_std = calloc(nmemb, size);
    IM_ASSERT_PTR_NULL(ptr_ft); // Should be NULL according to your definition
   // IM_ASSERT_PTR_NULL(ptr_std); // May return NULL or any mem address, see 'man calloc'
    free(ptr_ft);
    //free(ptr_std);

    // Test 8: Memory initialization check
    nmemb = 50;
    size = sizeof(char);
    ptr_ft = ft_calloc(nmemb, size);
    IM_ASSERT_PTR_NOT_NULL(ptr_ft);
    for (size_t i = 0; i < nmemb * size; i++)
    {
        IM_ASSERT_INT_EQUAL(((unsigned char *)ptr_ft)[i], 0);
    }
    free(ptr_ft);


    // Test 9: Non-zero memory before allocation
    nmemb = 20;
    size = sizeof(int);
    ptr_ft = malloc(nmemb * size);
    memset(ptr_ft, 0xFF, nmemb * size); // Set to non-zero
    free(ptr_ft);
    ptr_ft = ft_calloc(nmemb, size);
    IM_ASSERT_PTR_NOT_NULL(ptr_ft);
    for (size_t i = 0; i < nmemb * size; i++)
    {
        IM_ASSERT_INT_EQUAL(((unsigned char *)ptr_ft)[i], 0);
    }
    free(ptr_ft);
}
