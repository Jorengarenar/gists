// An example of proprerly used `goto` in C code - for error handling and cleanup
// Code orginates from Reddit thread: https://www.reddit.com/r/C_Programming/comments/g3juie/

World* World_load_from_path(const char* file_path, _Bool load_entities)
{
    int error_number = 0;

    FILE* file = fopen(file_path, "r");
    if (!file) {
        error_number = 1;
        goto fail1;
    }

    World* world = calloc(1, sizeof(World));
    if (!world) {
        error_number = 2;
        goto fail2;
    }

    world->level = Level_load_from_file(file);
    if (!world->level) {
        error_number = 3;
        goto fail3;
    }

    world->viewport = Viewport_create();
    if (!world->viewport) {
        error_number = 4;
        goto fail4;
    }

    if (load_entities) {
        // ...
    }

    fclose(file);
    return world;

    // Error handling
fail4:  Level_destroy(world->level);
fail3:  free(world);
fail2:  fclose(file);
fail1:  printf("[World] failed to load from %s. error number: %d\n", file_path, error_number);

    return NULL;
}
