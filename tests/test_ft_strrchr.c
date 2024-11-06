#include <string.h>   // For comparison with the standard strrchr
#include "../imtest42/imtest42.h"
#include "../libft.h"

void test_ft_strrchr(void)
{
    const char *s;
    char *result_ft;
    char *result_std;

    // Test 1: Character present in string
    s = "hello world";
    result_ft = ft_strrchr(s, 'o');
    result_std = strrchr(s, 'o');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 2: Character not present in string
    s = "hello world";
    result_ft = ft_strrchr(s, 'x');
    result_std = strrchr(s, 'x');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 3: Search for null terminator
    s = "hello world";
    result_ft = ft_strrchr(s, '\0');
    result_std = strrchr(s, '\0');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 4: Empty string
    s = "";
    result_ft = ft_strrchr(s, 'a');
    result_std = strrchr(s, 'a');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 5: Character at the beginning
    s = "abcde";
    result_ft = ft_strrchr(s, 'a');
    result_std = strrchr(s, 'a');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 6: Character at the end
    s = "abcde";
    result_ft = ft_strrchr(s, 'e');
    result_std = strrchr(s, 'e');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 7: Multiple occurrences
    s = "banana";
    result_ft = ft_strrchr(s, 'a');
    result_std = strrchr(s, 'a');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 9: Character with value greater than 127
    s = "hello\xFFworld";
    result_ft = ft_strrchr(s, '\xFF');
    result_std = strrchr(s, '\xFF');
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);

    // Test 10: Negative character code
    s = "abc";
    result_ft = ft_strrchr(s, -1);
    result_std = strrchr(s, -1);
    IM_ASSERT_PTR_EQUAL(result_ft, result_std);
}
