<?hh

/* Close a DBA database.
 */
<<__Native>>
function dba_close(resource $handle): void;

/* Delete DBA entry specified by key.
 */
<<__Native>>
function dba_delete(string $key, resource $handle): bool;

/* Check whether key exists.
 */
<<__Native>>
function dba_exists(string $key, resource $handle): bool;

/* Fetch data specified by key.
 */
<<__Native>>
function dba_fetch(string $key, resource $handle): mixed;

/* Fetch first key.
 */
<<__Native>>
function dba_firstkey(resource $handle): mixed;

/* List all the handlers available.
 */
<<__Native>>
function dba_handlers(bool $full_info = false): array;

/* Insert entry.
 */
<<__Native>>
function dba_insert(string $key, string $value, resource $handle): bool;

/* Splits a key in string representation into array representation.
 */
<<__Native>>
function dba_key_split(mixed $key): mixed;

/* List all open database files.
 */
<<__Native>>
function dba_list(): array;

/* Fetch next key.
 */
<<__Native>>
function dba_nextkey(resource $handle): mixed;

/* Open database.
 */
<<__Native>>
function dba_open(string $path , string $mode, string $handler = '', ...$argv): mixed;

/* Optimize database.
 */
<<__Native>>
function dba_optimize(resource $handle): bool;

/* Optimize database.
 */
<<__Native>>
function dba_optimize(resource $handle): bool;

/* Open database persistently.
 */
<<__Native>>
function dba_popen(string $path , string $mode, string $handler = '', ...$argv): mixed;

/* Replace or insert entry.
 */
<<__Native>>
function dba_replace(string $key, string $value, resource $handle): bool;

/* Synchronize database.
 */
<<__Native>>
function dba_sync(resource $handle): bool;
