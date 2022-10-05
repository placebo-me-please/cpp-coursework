.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge19B - Debug ]----------"
	@cd "Challenge19B" && "$(MAKE)" -f  "Challenge19B.mk"
clean:
	@echo "----------Cleaning project:[ Challenge19B - Debug ]----------"
	@cd "Challenge19B" && "$(MAKE)" -f  "Challenge19B.mk" clean
