CC = gcc
CCFLAGS = -std=c99 -g3 -Wall -Werror -pedantic -fsanitize=address

# test_reading objects and sources
test_reading_objects = tests/test_reading/test.o src/reading/reading.o
test_reading_src = tests/test_reading/test.c src/reading/reading.c

# test_reading output directory
test_reading_out_dir = tests/test_reading/

test_reading:  $(test_reading_objects)
	$(CC) $(CCFLAGS) -o $(test_reading_out_dir)output $^

run_test_reading: $(test_reading_out_dir)output
	./$(test_reading_out_dir)output

clean_test_reading:
	$(RM) -f $(test_reading_objects) $(test_reading_out_dir)output