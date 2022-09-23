.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge15 - Debug ]----------"
	@cd "Challenge15" && "$(MAKE)" -f  "Challenge15.mk"
clean:
	@echo "----------Cleaning project:[ Challenge15 - Debug ]----------"
	@cd "Challenge15" && "$(MAKE)" -f  "Challenge15.mk" clean
