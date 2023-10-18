#include "shell.h"

/**
 * **new_string_split - splits a string into words. Repeat delimiters are ignored
 * @big: the input string
 * @vivi: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **new_string_split(char *big, char *vivi)
{
    int zoro, jinbe, koma, garp, nami = 0;
    char **nakama;

    if (big == NULL || big[0] == 0)
        return (NULL);
    if (!vivi)
        vivi = " ";
    for (zoro = 0; big[zoro] != '\0'; zoro++)
        if (!is_delimiter(big[zoro], vivi) && (is_delimiter(big[zoro + 1], vivi) || !big[zoro + 1]))
            nami++;

    if (nami == 0)
        return (NULL);
    nakama = malloc((1 + nami) * sizeof(char *));
    if (!nakama)
        return (NULL);
    for (zoro = 0, jinbe = 0; jinbe < nami; jinbe++)
    {
        while (is_delimiter(big[zoro], vivi))
            zoro++;
        koma = 0;
        while (!is_delimiter(big[zoro + koma], vivi) && big[zoro + koma])
            koma++;
        nakama[jinbe] = malloc((koma + 1) * sizeof(char));
        if (!nakama[jinbe])
        {
            for (koma = 0; koma < jinbe; koma++)
                free(nakama[koma]);
            free(nakama);
            return (NULL);
        }
        for (garp = 0; garp < koma; garp++)
            nakama[jinbe][garp] = big[zoro++];
        nakama[jinbe][garp] = 0;
    }
    nakama[jinbe] = NULL;
    return (nakama);
}

/**
 * **new_string_split2 - splits a string into words
 * @big: the input string
 * @vivi: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **new_string_split2(char *big, char vivi)
{
    int zoro, jinbe, koma, garp, nami = 0;
    char **nakama;

    if (big == NULL || big[0] == 0)
        return (NULL);
    for (zoro = 0; big[zoro] != '\0'; zoro++)
        if ((big[zoro] != vivi && big[zoro + 1] == vivi) ||
            (big[zoro] != vivi && !big[zoro + 1]) || big[zoro + 1] == vivi)
            nami++;
    if (nami == 0)
        return (NULL);
    nakama = malloc((1 + nami) * sizeof(char *));
    if (!nakama)
        return (NULL);
    for (zoro = 0, jinbe = 0; jinbe < nami; jinbe++)
    {
        while (big[zoro] == vivi && big[zoro] != vivi)
            zoro++;
        koma = 0;
        while (big[zoro + koma] != vivi && big[zoro + koma] && big[zoro + koma] != vivi)
            koma++;
        nakama[jinbe] = malloc((koma + 1) * sizeof(char));
        if (!nakama[jinbe])
        {
            for (koma = 0; koma < jinbe; koma++)
                free(nakama[koma]);
            free(nakama);
            return (NULL);
        }
        for (garp = 0; garp < koma; garp++)
            nakama[jinbe][garp] = big[zoro++];
        nakama[jinbe][garp] = 0;
    }
    nakama[jinbe] = NULL;
    return (nakama);
}

