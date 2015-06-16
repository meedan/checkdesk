<?php

/**
 * Very fast hash based lookup interface.
 *
 * This will work for any key-value store whether it's APC, Redis, memcache...
 * Rationale behind this is that Drupal calls hundreds of time per request the
 * drupal_lookup_path() function and we need it to be very fast. The key of
 * success to keep it stupid simple and coherent as the same time is that we
 * consider this backend as a cache (more or less permanent) that might be
 * cleared at any time, and synchronized as when necessary or incrementally.
 * This should be very fast.
 *
 * Redis implementation will be the following:
 *
 * Aliases are stored into a Redis HASH and are stored per language basis.
 * Key is:
 *   [SITEPREFIX:]path:dst:LANGUAGE
 * Keys inside the hash are a MD5() of the source and values are the alias
 *
 * Sources are also stored the same way except the HASH key is the following:
 *   [SITEPREFIX:]path:src:LANGUAGE
 * Keys inside the hash are a MD5() of the alias and values are the sources.
 *
 * In both case values are a comma separated list of string values.
 *
 * The MD5() should give us low collision algorithm and we'll keep it until
 * no one experiences any problem.
 *
 * Alias and sources are always looked up using the language, hence the
 * different keys for different languages.
 */
interface Redis_Path_HashLookupInterface
{
    /**
     * Alias HASH key prefix
     */
    const KEY_ALIAS = 'path:a';

    /**
     * Source HASH key prefix
     */
    const KEY_SOURCE = 'path:s';

    /**
     * Null value (not existing yet cached value)
     */
    const VALUE_NULL = '!';

    /**
     * Values separator for hash values
     */
    const VALUE_SEPARATOR = '#';

    /**
     * Alias is being inserted with the given source
     *
     * @param string $source
     * @param string $alias
     * @param string $language
     */
    public function saveAlias($source, $alias, $language = null);

    /**
     * Alias is being deleted for the given source
     *
     * @param string $source
     * @param string $alias
     * @param string $language
     */
    public function deleteAlias($source, $alias, $language = null);

    /**
     * A language is being deleted
     *
     * @param string $language
     */
    public function deleteLanguage($language);

    /**
     * Lookup any alias for the given source
     *
     * First that has been inserted wins over the others
     *
     * @param string $source
     * @param string $language
     *
     * @return string|null|false
     *   - The string value if found
     *   - null if not found
     *   - false if set as non existing
     */
    public function lookupAlias($source, $language = null);

    /**
     * Lookup any source for the given alias
     *
     * First that has been inserted wins over the others
     *
     * @param string $alias
     * @param string $language
     *
     * @return string|null|false
     *   - The string value if found
     *   - null if not found
     *   - false if set as non existing
     */
    public function lookupSource($alias, $language = null);
}
