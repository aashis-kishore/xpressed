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


## test_evaluation_stack: start

# test_evaluation_stack objects and sources
test_evaluation_stack_objects = tests/test_evaluation/test_stack/test.o src/evaluation/stack/stack.o
test_evaluation_stack_src = tests/test_evaluation/test_stack/test.c src/evaluation/stack/stack.c

# test_evaluation output directory
test_evaluation_stack_out_dir = tests/test_evaluation/

test_evaluation_stack: $(test_evaluation_stack_objects)
	$(CC) $(CCFLAGS) -o $(test_evaluation_stack_out_dir)output $^

run_test_evaluation_stack: $(test_evaluation_stack_out_dir)/output
	./$(test_evaluation_stack_out_dir)/output

clean_test_evaluation_stack:
	$(RM) -f $(test_evaluation_stack_objects) $(test_evaluation_stack_out_dir)/output

##


## run all tests: start

run_all_tests: \
	test_reading	\
	test_sanitization	\
	test_evaluation_stack	\
							\
	run_test_reading	\
	run_test_sanitization	\
	run_test_evaluation_stack	\
								\
	clean_test_reading	\
	clean_test_sanitization	\
	clean_test_evaluation_stack	\
	
## end

.PHONY: test_reading run_test_reading clean_test_reading