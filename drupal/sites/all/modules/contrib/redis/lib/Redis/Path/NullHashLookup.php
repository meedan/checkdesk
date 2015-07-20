<?php

/**
 * Null implementation.
 */
class Redis_Path_NullHashLookup implements Redis_Path_HashLookupInterface
{
    public function saveAlias($source, $alias, $language = null)
    {
    }

    public function deleteAlias($source, $alias, $language = null)
    {
    }

    public function deleteLanguage($language)
    {
    }

    public function lookupAlias($source, $language = null)
    {
    }

    public function lookupSource($alias, $language = null)
    {
    }
}
