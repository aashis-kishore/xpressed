CC = gcc
CCFLAGS = -std=c99 -g3 -Wall -Werror -pedantic -fsanitize=address


## test_reading: start

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

## end


## test_sanitization: start

# test_sanitization_objects and sources
test_sanitization_objects = tests/test_sanitization/test.o src/sanitization/sanitization.o
test_sanitization_src = tests/test_sanitization/test.c src/sanitization/sanitization.c

# test_sanitization output directory
test_sanitization_out_dir = tests/test_sanitization/

test_sanitization:  $(test_sanitization_objects)
	$(CC) $(CCFLAGS) -o $(test_sanitization_out_dir)output $^

run_test_sanitization: $(test_sanitization_out_dir)output
	./$(test_sanitization_out_dir)output

clean_test_sanitization:
	$(RM) -f $(test_sanitization_objects) $(test_sanitization_out_dir)output

## end