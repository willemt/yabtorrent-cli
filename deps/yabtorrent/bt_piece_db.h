//#ifndef BT_PIECE_DB_H
#define BT_PIECE_DB_H

/* piece database */
typedef void* bt_piecedb_t;

/**
 * @return newly initialised piece database */
bt_piecedb_t *bt_piecedb_new();

/**
 * Obtain this piece from the piece database
 * @return piece specified by piece_idx; otherwise NULL */
void *bt_piecedb_get(void* dbo, const unsigned int idx);

#if 0 /* planned for future */
/**
 * @return 1 if we have npieces pieces from idx */
int bt_piecedb_contains_piecerange(void* dbo,
                                   const unsigned int idx,
                                   const unsigned int pieces);
#endif

/**
 * @return number of pieces */
int bt_piecedb_count(bt_piecedb_t * db);

/**
 * Add a piece with this sha1sum
 * @param length Piece's size in bytes
 * @return piece idx, otherwise -1 on error */
//int bt_piecedb_add(bt_piecedb_t * db, const char *sha1, unsigned int size, );
int bt_piecedb_add(bt_piecedb_t * db, unsigned int npieces);

/**
 * Remove a piece with this idx */
void bt_piecedb_remove(bt_piecedb_t * db, int idx);

/**
 * @return number of pieces downloaded */
int bt_piecedb_get_num_completed(bt_piecedb_t * db);

/**
 * @return number of pieces downloaded */
int bt_piecedb_get_num_completed(bt_piecedb_t * db);

/**
 * @return 1 if all complete, 0 otherwise */
int bt_piecedb_get_length(bt_piecedb_t * db);

/**
 * Print a string of all the downloaded pieces */
void bt_piecedb_print_pieces_downloaded(bt_piecedb_t * db);

/**
 * Increase total file size by this file's size */
void bt_piecedb_increase_piece_space(bt_piecedb_t* db, const int size);

/**
 * @return 1 if all complete, 0 otherwise */
int bt_piecedb_all_pieces_are_complete(bt_piecedb_t* db);

void bt_piecedb_set_diskstorage(bt_piecedb_t * db,
                                bt_blockrw_i * irw, void *udata);

void* bt_piecedb_get_diskstorage(bt_piecedb_t * db);


int bt_piecedb_add_with_hash_and_size(bt_piecedb_t * db,
                                      const char *sha1sum,
                                      const int piece_bytes_size);

int bt_piecedb_add_at_idx(bt_piecedb_t * db, unsigned int npieces, int idx);

//#endif /* BT_PIECE_DB_H */
