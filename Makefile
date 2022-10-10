.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge19D - Debug ]----------"
	@cd "Challenge19D" && "$(MAKE)" -f  "Challenge19D.mk"
clean:
	@echo "----------Cleaning project:[ Challenge19D - Debug ]----------"
	@cd "Challenge19D" && "$(MAKE)" -f  "Challenge19D.mk" clean
