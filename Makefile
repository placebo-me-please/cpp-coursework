.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge19A - Debug ]----------"
	@cd "Challenge19/Challenge_1" && "$(MAKE)" -f  "Challenge19A.mk"
clean:
	@echo "----------Cleaning project:[ Challenge19A - Debug ]----------"
	@cd "Challenge19/Challenge_1" && "$(MAKE)" -f  "Challenge19A.mk" clean
